#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include "finally.hpp"


enum class WaveType : uint8_t {
	Square, Sine
};

struct AudioData {
	unsigned int pos; /* which sample we are up to */
	int len; /* how many samples left to play, stops when <= 0*/
	double freq; /*audio frequency in cycles per sample*/
	double vol; /*audio volume, 0 - ~32000*/
	bool high;
	WaveType wave_type;
};


static bool init_sdl();
static void quit_sdl();
static void print_spec_info(const SDL_AudioSpec& spec, const char* msg = nullptr);
static void gen_sine_wave(int seconds, double freq, SDL_AudioDeviceID dev,
                           const SDL_AudioSpec& spec, AudioData* data);
static void gen_quad_wave(int seconds, double freq, SDL_AudioDeviceID dev,
                           const SDL_AudioSpec& spec, AudioData* data);
void audio_callback(void* userdata, uint8_t* stream, int len);

int main()
{
	if (init_sdl() != true)
		return -1;

	const auto sdl_quitter = finally([] {
		quit_sdl();
	});

	AudioData audio_data{};
	SDL_AudioSpec want{}, have{};
	
	want.freq = 44100;
	want.format = AUDIO_S16;
	want.channels = 2;
	want.samples = 4096;
	want.callback = &audio_callback;
	want.userdata = &audio_data;

	print_spec_info(want, "[SDL] AudioSpec Desired");

	const SDL_AudioDeviceID dev =
	  SDL_OpenAudioDevice(nullptr, 0, &want, &have,
	                       SDL_AUDIO_ALLOW_ANY_CHANGE);
	if (dev == 0) {
		fprintf(stderr, "error %s\n", SDL_GetError());
		return -1;
	}

	const auto audio_device_guard = finally([dev] {
		SDL_CloseAudioDevice(dev);
	});

	print_spec_info(have, "[SDL] AudioSpec Obtained");
	
	for (int i = 100; i <= 1000; i += 100) {
		gen_sine_wave(2, i, dev, have, &audio_data);
		gen_quad_wave(2, i, dev, have, &audio_data);
	}
	
	return 0;
}

void gen_sine_wave(const int seconds, const double freq, const SDL_AudioDeviceID dev,
		const SDL_AudioSpec& spec, AudioData* const data)
{
	data->pos = 0;
	data->len = spec.freq * seconds * spec.channels;
	data->freq = (freq / 2) / spec.freq;
	data->vol = 6000;
	data->wave_type = WaveType::Sine;
	SDL_PauseAudioDevice(dev, 0); /* play */
	while (data->len > 0) {
		SDL_Delay(10);
	}
	SDL_PauseAudioDevice(dev, 1); /* pause */
}

void gen_quad_wave(const int seconds, const double freq, const SDL_AudioDeviceID dev,
		const SDL_AudioSpec& spec, AudioData* const data)
{
	data->pos = 0;
	data->len = spec.freq * seconds * spec.channels;
	data->freq = spec.freq / freq;
	data->vol = 3000;
	data->wave_type = WaveType::Square;
	SDL_PauseAudioDevice(dev, 0); /* play */
	while (data->len > 0) {
		SDL_Delay(10);
	}
	SDL_PauseAudioDevice(dev, 1); /* pause */
}

void audio_callback(void* const userdata, uint8_t* const stream, int len)
{
	len /= sizeof(uint16_t);
	AudioData& data = *reinterpret_cast<AudioData*>(userdata);
	int16_t* const buffer = reinterpret_cast<int16_t*>(stream);

	switch (data.wave_type) {
	case WaveType::Square:
		for (int i = 0; i < len; ++i) {
			if (data.pos >= data.freq) {
				data.high = !data.high;
				data.pos = 0;
			}
			buffer[i] = data.high ? data.vol : -data.vol;
			++data.pos;
		}
		break;
	case WaveType::Sine:
		for (int i = 0; i < len; ++i) {
			buffer[i] = 
			  data.vol * sin(2 * M_PI * data.freq * data.pos++);
		}
		break;
	default:
		break;
	}

	data.len -= len;
}

void print_spec_info(const SDL_AudioSpec& spec, const char* const msg /* = nullptr */)
{
	if (msg != nullptr)
		printf("%s\n", msg);

	printf("frequency: %d\n"
	       "format: float %d signed %d bigendian %d size %d\n"
	       "channels: %d\n"
	       "samples: %d\n",
	       spec.freq, SDL_AUDIO_ISFLOAT(spec.format), 
	       SDL_AUDIO_ISSIGNED(spec.format), 
	       SDL_AUDIO_ISBIGENDIAN(spec.format), 
	       SDL_AUDIO_BITSIZE(spec.format), 
	       spec.channels, spec.samples);
}

bool init_sdl()
{
	if (SDL_Init(SDL_INIT_AUDIO) != 0) {
		fprintf(stderr, "error %s\n", SDL_GetError());
		return false;
	}

	return true;
}

void quit_sdl()
{
	SDL_Quit();
}


