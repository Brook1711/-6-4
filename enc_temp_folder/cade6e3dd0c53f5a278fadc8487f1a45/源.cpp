#include<iostream>
#include <iomanip>

using namespace std;

int main()
{
	int M(0), N(0); //M为学生数，N为学科数。
	bool T = false;
	cin >> M >> N ;
	float **p = new float*[M];
	for (int i = 0; i < N; i++)
	{
		p[i] = new float[N];
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> p[i][j];

		}
	}
	float * average1 = new float[M];
	float * average2 = new float[N];
	for (int i = 0; i < M; i++)
	{
		float sum(0);
		for (int j = 0; j < N; j++)
		{
			sum += p[i][j];
		}
		average1[i] = sum / N;
		if(i==0)
			cout <<fixed << setprecision(2) << average1[i];
		else
			cout << " " << fixed << setprecision(2) << average1[i];

	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		float sum(0);
		for (int j = 0; j < M; j++)
		{
			sum += p[j][i];
		}
		average2[i] = sum / M;
		if(i==0)
			cout << fixed << setprecision(2) << average2[i] ;
		else
			cout << " " << fixed << setprecision(2) << average2[i];

	}
	cout << endl;
	int count(0);
	for (int i = 0; i < M; i++)
	{
		bool T = true;
		for (int j = 0; j < N; j++)
		{
			if (average2[j] > p[i][j])
				T = false;
		}
		if (T)
			count++;
	}
	cout << count;


	delete[] average1;
	delete[] average2;
	for (int i = 0; i < N; i++)
	{
		delete[] p[i];
	}
	delete p;
	system("pause");
	return 0;
}