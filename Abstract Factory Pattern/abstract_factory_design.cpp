#include<bits/stdc++.h>
using namespace std;

class IButton{
    public:
        virtual void press()=0;
};

class ITextBox{
    public:
        virtual void showText()=0;
};

class MacButton : public IButton {
    public:
        virtual void press(){
            cout<<"Mac button pressed"<<endl;
        }

};
class WinButton: public IButton{
    public:
        virtual void press(){
            cout<<"Windows button pressed"<<endl;
        }

};
class MacTextBox: public ITextBox{
    public:
        virtual void showText(){
            cout<<"Mac TexBox showed"<<endl;
        }

};
class WinTextBox: public ITextBox{
    public:
        virtual void showText(){
            cout<<"Windows TexBox showed"<<endl;
        }

};
class IFactory{
    public:
        virtual IButton* CreateButton() = 0;
        virtual ITextBox* CreateTextBox() = 0;
};

class MacFactory : public IFactory{
    public:
        IButton* CreateButton(){
            return new MacButton();
        }
        ITextBox* CreateTextBox(){
            return new MacTextBox();
        }
};
class WinFactory: public IFactory{
    public:
        IButton* CreateButton(){
            return new WinButton();
        }
        ITextBox* CreateTextBox(){
            return new WinTextBox();
        }
};

class GUIAbstractFactory{
    public:
        static IFactory* CreateFactory(string OsType){
            if(OsType=="Windows"){
                return new WinFactory();
            }
            else if(OsType=="Mac"){
                return new MacFactory();
            }
            else{
                return new MacFactory();
            }
        }

};

int main(){
    cout<<"Enter your machine OS"<<endl;
    string OsType;
    cin>>OsType;
    IFactory* fact = GUIAbstractFactory::CreateFactory(OsType);

    IButton* button = fact->CreateButton();
    button->press();
    ITextBox* text_box = fact->CreateTextBox();
    text_box->showText();

    return 0;
}