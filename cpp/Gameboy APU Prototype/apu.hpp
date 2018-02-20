#ifndef GAMEBOY_APU_PROTOTYPE_APU_HPP_
#define GAMEBOY_APU_PROTOTYPE_APU_HPP_
#include <stdint.h>

struct Apu {
	struct {
		union {
			uint8_t value;
			struct {
				uint8_t sweep_shift : 3;
				uint8_t sweep_inc_dec : 1;
				uint8_t sweep_time : 3;
			};
		} nr10;


		union {
			uint8_t value;
			struct {
				uint8_t length_data : 6;
				uint8_t wave_pattern : 2;
			};
		} nr11;

		union {
			uint8_t value;
			struct {
				uint8_t envelop_sweep : 3;
				uint8_t envelop_dir : 1;
				uint8_t initial_vol : 4;
			};
		} nr12;

		union {
			uint8_t freq_lower_bits;
		} nr13;

		union {
			uint8_t value;
			struct {
				uint8_t freq_higher_bits : 3;
				uint8_t dummy : 3;
				uint8_t counter : 1;
				uint8_t inital : 1;
			};
		} nr14;

	} channel_1;

};

#endif
