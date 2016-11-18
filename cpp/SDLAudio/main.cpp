#include <stdint.h>
#include <stdio.h>
#include <SDL2/SDL.h>


static bool init_sdl();
static void quit_sdl();
static void print_spec_info(const SDL_AudioSpec& spec, const char* msg = nullptr);
void audio_callback(void* data, uint8_t* stream, int len);


int main()
{
	if (init_sdl() != true)
		return -1;

	const struct SDL_Quitter {
		~SDL_Quitter() { quit_sdl(); }
	} sdl_quitter;

	SDL_AudioSpec want, have;
	want.freq = 22050;
	want.format = AUDIO_S16LSB;
	want.channels = 2;
	want.samples = 4096;
	want.callback = audio_callback;
	print_spec_info(want, "[SDL] AudioSpec Desired");
	const SDL_AudioDeviceID dev = SDL_OpenAudioDevice(nullptr, 0, &want,
	                              &have, SDL_AUDIO_ALLOW_ANY_CHANGE);
	if (dev == 0) {
		fprintf(stderr, "error %s\n", SDL_GetError());
		return -1;
	}

	const struct SDL_AudioDevCloser {
		~SDL_AudioDevCloser() { SDL_CloseAudioDevice(dev); }
		const SDL_AudioDeviceID dev;
	} sdl_audio_dev_closer { dev };

	print_spec_info(have, "[SDL] AudioSpec Obtained");

	return 0;
}



void audio_callback(void* const data, uint8_t* const stream, const int len)
{
	printf("data addr: %zX\n", reinterpret_cast<size_t>(data));
	for (int i = 0; i < len; ++i)
		printf("%d: %u\n", i, static_cast<unsigned>(stream[i]));
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










