#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cerr << "Vvedite kol chisel ";
    size_t number_count;
    cin >> number_count;
    vector <double> numbers(number_count);
    cerr <<"vvedite znacheniya ";
    for (size_t i = 0; i < number_count; i++)
    {
        cin >> numbers[i];
    }
    size_t bin_count;
    cerr << "kol korzin ";
    cin >> bin_count;

    vector <size_t> bins(bin_count, 0);
    double min = numbers[0];
    double max = numbers[0];
    for (double number : numbers)
    {
        if (number < min)
        {
            min = number;
        }

        if (number > max)
        {
            max = number;
        }
    }

    size_t bin_index;

    for (double number : numbers)
    {

        if (number != max)
        {
            bin_index = (size_t)((number - min) * bin_count / (max - min));

        }
        else
        {
            bin_index = (bin_count - 1);

        }
        bins[bin_index]++;
    }
    const size_t max_ast = 76;
    const size_t max_wight = 80;
    double koef = 1;
    size_t max_count = 0;

    for (size_t bin : bins)
    {
        if (bin > max_count)
        {
            max_count = bin;
        }
    }

    if (max_count > max_ast)
    {
        koef = static_cast <double> (max_ast) / max_count;
    }


    for (size_t bin : bins)
    {
        cout << ((float)(bin)/number_count*100.) <<"%";
        /*if (bin < 10)
        {

        	//cout << "    " << bin << "|";
        }
        else if ((bin > 10) && (bin < 100)||(bin==10))
        {
        	//cout << "  " << bin << "|";
        }
        else if ((bin>100) && (bin<1000)||(bin==100))
        {
        	//cout << bin << "|";
        }
        else if (bin>1000)
        {
        	cout << "anomalni nomer korzini";
        }*/
        cout << '|';
        size_t height = bin * koef;
        for (size_t i = 0; i < height; i++)
        {
            cout << "*";
        }
        cout << '\n';
    }


    return 0;
}
