#include<bits/stdc++.h>
using namespace std;

class pizza{
    string pizza_base;
    string sauces;
    string toppings;

    public:
        
        void prepare_base(string base){
            pizza_base = base;
        }
        void put_sauces(string sauce){
            sauces = sauce;
        }
        void add_toppings(string topping){
            toppings = topping;
        }
        void show_pizza(){
            cout<<"This is "<<pizza_base<<" with the sauces "<<sauces<<" and toppings in it is "<<toppings<<endl;
            cout<<"Thanks for your order!!"<<endl;
        }

};

class pizza_builder{
    public:
        virtual void prepare_base() = 0;
        virtual void put_sauces() = 0;
        virtual void add_toppings() = 0;

};

class spicy_pizza_builder: public pizza_builder{
    pizza pizza_obj;

    public:
    void prepare_base(){
        pizza_obj.prepare_base("spicy_base");
    }
    void put_sauces(){
        pizza_obj.put_sauces("spicy_sauces");
    }
    void add_toppings(){
        pizza_obj.add_toppings("spicy_toppings");
    }
    pizza get_pizza(){
            return pizza_obj;
        }
};

class nonveg_pizza_builder: public pizza_builder{
    pizza pizza_obj;
    public:
    void prepare_base(){
        pizza_obj.prepare_base("nonveg_base");
    }
    void put_sauces(){
        pizza_obj.put_sauces("nonveg_sauces");
    }
    void add_toppings(){
        pizza_obj.add_toppings("nonveg_toppings");
    }
    pizza get_pizza(){
            return pizza_obj;
        }
};

class cook{
    public:
        void make_pizza(pizza_builder &pizza_bldr){
            pizza_bldr.prepare_base();
            pizza_bldr.put_sauces();
            pizza_bldr.add_toppings();
        }
};

int main(){
    cook cook_obj;

    nonveg_pizza_builder nonveg_pizza_bldr;
    cook_obj.make_pizza(nonveg_pizza_bldr);
    pizza non_veg_pizza = nonveg_pizza_bldr.get_pizza();
    non_veg_pizza.show_pizza();

    return 0;
}