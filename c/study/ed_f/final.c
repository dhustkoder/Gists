#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Sex { kMale, kFemale };
typedef enum Sex sex_t;



static inline float calc_bmi(const float kg, const float height)
{
	return kg / (height * height);
}


static inline float calc_bmr(const sex_t sex, const int age, const float kg, const float heightf)
{
	const int height = heightf * 100; 

	if (sex == kMale)
		return 66.47f + (13.75f * kg) + (5.f * height) - (6.76f * age);
	else
		return 655.1f + (9.56f * kg) + (1.85f * height) - (4.68f * age);
}


static inline float calc_whr(const int waist, const int hip)
{
	return waist / hip;
}


static inline float calc_cals(const float bmr, const int hrs)
{
	return (bmr / 24) * hrs;
}


static inline const char* bmi_descr(const float bmi)
{
	if (bmi < 18.5)
		return "abaixo do peso";
	else if (bmi <= 24.9)
		return "peso ideal";
	else if (bmi <= 29.9)
		return "levemente acima do peso";
	else if (bmi <= 34.9)
		return "obesidade grau I";
	else if (bmi <= 39.9)
		return "obesidade grau II";
	else
		return "obesidade III";
}


static inline const char* whr_descr(const sex_t sex, const int age, const float whr)
{
	#define WHRCASE(low, mid, high) do {              \
		if (whr < low) return "baixo";            \
		else if (whr <= mid) return "moderado";   \
		else if (whr <= high) return "alto";      \
		else return "muito alto";                 \
	} while (0)


	if (sex == kMale) {
		if (age < 30)
			WHRCASE(0.83, 0.88, 0.94);
		else if (age < 40)
			WHRCASE(0.84, 0.91, 0.96);
		else if (age < 50)
			WHRCASE(0.88, 0.95, 1);
		else if (age < 60)
			WHRCASE(0.90, 0.96, 1.02);
		else
			WHRCASE(0.91, 0.98, 1.03);
	} else {
		if (age < 30)
			WHRCASE(0.71, 0.77, 0.82);
		else if (age < 40)
			WHRCASE(0.72, 0.78, 0.84);
		else if (age < 50)
			WHRCASE(0.73, 0.79, 0.87);
		else if (age < 60)
			WHRCASE(0.74, 0.81, 0.88);
		else
			WHRCASE(0.76, 0.83, 0.90);
	}
}



static inline void scan(const char* const msg, const char* const scan_fmt, void* const ptr)
{
	printf("%s: ", msg);
	scanf(scan_fmt, ptr);
	putchar('\n');
}


int main(int argc, char** argv)
{
	sex_t sex;
	int age, waist, hip;
	float kg, height;

	scan("Enter your sex [0 = male, 1 = female]", "%i", &sex);
	scan("Enter your age", "%i", &age);
	scan("Enter your waist", "%i", &waist);
	scan("Enter your hip", "%i", &hip);
	scan("Enter your weight", "%f", &kg);
	scan("Enter your height", "%f", &height);

	const float bmi = calc_bmi(kg, height);
	const float bmr = calc_bmr(sex, age, kg, height);
	const float whr = calc_whr(waist, hip);

	printf("IMC: %.2f %s\n"
	       "TMB: %.2f\n"
	       "calorias por hora: %.2f\n"
	       "RCQ: %f %s\n",
	       bmi, bmi_descr(bmi),
	       bmr, calc_cals(bmr, 1),
	       whr, whr_descr(sex, age, whr));

	return EXIT_SUCCESS;
}


