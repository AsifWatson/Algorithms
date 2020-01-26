#include<bits/stdc++.h>
using namespace std;

void multiply(string num1, string num2)
{
	int n1 = num1.size();
	int n2 = num2.size();

	vector<int> result(n1 + n2, 0);

	int i_n1 = 0;
	int i_n2 = 0;

	for (int i=n1-1; i>=0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		i_n2 = 0;

		for (int j=n2-1; j>=0; j--)
		{
			int n2 = num2[j] - '0';
			int sum = n1*n2 + result[i_n1 + i_n2] + carry;
			carry = sum/10;
			result[i_n1 + i_n2] = sum % 10;
			i_n2++;
		}

		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		i_n1++;
	}

	int i = result.size()-1;
	while (i>=0 && result[i] == 0)
	i--;

	if (i == -1)
	cout<<"0";
	while (i >= 0)
    {
        cout<<result[i--];
    }
    cout<<endl;
}

int main()
{
	char str1[10010];
	char str2[10010];
	scanf("%s",str1);
	scanf("%s",str2);
	multiply(str1, str2);
	return 0;
}

