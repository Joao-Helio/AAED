#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

void PrintStack(stack<char> s)
{
    // If stack is empty then return
    if (s.empty())
        return;


    char x = s.top();

    // Pop the top element of the stack
    s.pop();

    // Recursively call the function PrintStack
    PrintStack(s);

    // Print the stack element starting
    // from the bottom
    cout << x << " ";

    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

int main()
{
	string fita;

	while (cin >> fita)
	{
		string resp;

		int cont = 0;
        stack <char> pilha;

        for ( int i=0; i < fita.size(); i++)
        {
            if (fita[i] == 'S')
				resp += 'B';
			else if (fita[i] == 'B')
			    resp += 'S';
			else if (fita[i] == 'C')
				resp += 'F';
			else if (fita[i] == 'F')
				resp += 'C';
        }
		cout << "RESP:" << resp << endl;
		for (int i=0; i < fita.size(); i++)
		{//puts("entrou F");
			if (pilha.empty() || pilha.top() != resp[i])
				{
				    pilha.push(fita[i]);
                    puts("PILHA:");
                    PrintStack(pilha);
                    puts(" ");
				}
			else
			{
				while (true)
			    {//puts("entrou W");

					if (pilha.empty())
			        {i--;//puts("saiu");
					    break;}



                    else if (resp[i] == pilha.top() )
                    {
                        cont++;  puts("SOBE CONTADOR E TIRA DA PILHA");
                        PrintStack(pilha);
                        puts(" ");
                        pilha.pop();
                        i++;
                        //puts("AQUI!!");

                    }



					else
					{

						i--;//puts("saiu");
					    break;
					}


					if (i >= resp.size())
					{
					    i--;//puts("saiu I");
					    break;
					}

				}
			}
		}

		printf("%d\n", cont);
	}

	system ("pause");
	return 0;
}
