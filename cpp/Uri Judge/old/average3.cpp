#include <iostream>
#include <utility>

template<std::size_t size>
float get_average(std::pair<float, float>(&notes)[size])
{
	float notesTotal = 0;
	float weightTotal = 0;

	for (const auto& note : notes) {
		notesTotal += note.first * note.second;
		weightTotal += note.second;
	}

	return notesTotal / weightTotal;
}


int main()
{
	using namespace std;

	pair<float, float> notes[4] = { 
		{0,2.0}, {0,3.0}, {0,4.0}, {0,1.0}
	};

	cin >> notes[0].first >> notes[1].first 
	    >> notes[2].first >> notes[3].first;

	const float average = get_average(notes);

	cout.precision(1);
	cout.setf(cout.fixed);
	cout << "Media: " << average << endl;
	
	if (average >= 7.0) {
		cout << "Aluno aprovado." << endl;
	} else if (average >= 5.0) {
		cout << "Aluno em exame." << endl;
		float examNote, finalAvr;
		cin >> examNote;
		finalAvr = (examNote + average) / 2.0;
		cout << "Nota do exame: " << examNote << endl;
		if (finalAvr >= 5.0)
			cout << "Aluno aprovado." << endl;
		else
			cout << "Aluno reprovado." << endl;

		cout << "Media final: " << finalAvr << endl;
	} else {
		cout << "Aluno reprovado." << endl;
	}
	

	return 0;
}


