#include <iostream>
#include <string>

using namespace std;

class Cell
{
    public:
        short int row;
        short int col;

    private:
        string text;
        string c1Text;
        string c2Text;
        short int l2;
        short int nextRow;
        short int nextCol;
        char c1;
        char c2;
        Cell *next;

    public:
        void setC1(char c)
        {
            c1 = c;
            short int c1int = c + 128;
            c1Text = to_string(c1int);
            text = text + c1Text;
        }

        char getC1(void)
        {
            return c1;
        }

        void setC2(char c)
        {
            c2 = c;
            short int c2int = c + 128;
            c2Text = to_string(c2int);
            text = text + c2Text;
            l2 = c2int % 100;
        }

        char getC2(void)
        {
            return c2;
        }

        void setNext(Cell *n)
        {
            next = n;
            if (c2Text.empty())
            {
                c2Text = "000";
                text = text + c2Text;
                l2 = 0;
            }
            if (NULL == n)
            {
                nextRow = 99;
                nextCol = 99;
            }
            else
            {
                nextRow = n -> row;
                nextCol = n -> col;
            }
            string nextRowText = to_string((nextRow + 100 - l2) % 100);
            string nextColText = to_string((nextCol + 100 - l2) % 100);
            text = text + nextRowText + nextColText;
        }

        Cell * getNext(void)
        {
            return next;
        }

        short int getL2(void)
        {
            return l2;
        }

        string getText(void)
        {
            return text;
        }
};

int main()
{
    Cell cell1;
    cell1.setC1('a');
    cout << cell1.getText() << endl;
    //cell1.setC2('b');
    //cout << cell1.getText() << endl;
    cell1.setNext(NULL);
    cout << cell1.getText() << endl;
}

