#include <iostream>

using namespace std;

class Document {
    string* text;

    public:
        Document(string text = "") : text(new string(text)) {}

        Document(const Document& obj) : text(new string(*obj.text)) {}

        Document& operator=(const Document& obj) {
            if(this != &obj) {
                delete text;
                text = new string(*obj.text);
            }
            return *this;
        }

        void setText(string text) {
            *this->text = text;
        }

        string getText() {
            return *text;
        }

        ~Document() {
            delete text;
        }
};

int main () {
    Document d1("Sample text");
    Document d2(d1);
    Document d3;
    d3 = d1;

    cout << "Before changing value of text in original document" << endl;
    cout << "Text in document 1 : " << d1.getText() << endl;
    cout << "Text in document 2 : " << d2.getText() << endl;
    cout << "Text in document 3 : " << d3.getText() << endl;

    d1.setText("Text changed");

    cout << endl << "After changing value of text in original document" << endl;
    cout << "Text in document 1 : " << d1.getText() << endl;
    cout << "Text in document 2 : " << d2.getText() << endl;
    cout << "Text in document 3 : " << d3.getText() << endl;

    return 0;
}
