#include<iostream>
#include"cauldron.h"
#include"ingredient.h"
using namespace std;

int main()
{
    //testing ingredients
    const int MAX = 8;
    const int NUM = 6;
    int i;

    // ingredient ** ings = new ingredient * [MAX];

    // cout<<"Creating standard ingredients...\n";
    // for(int i = 0; i < NUM; i++)
    // {
    //     ings[i] = new ingredient("fisheye", 8);
    // }
    // cout<<"done\n";
    // ings[6] = new ingredient("salamander", 4);
    // ings[7] = new ingredient("pumkin", 0);
    // cout<<"done.\n";


    // //copying ingredients
    // ingredient spI = ings[6];
    // ingredient spII = ings[1];
    // ingredient soup("soup", 9);
    // ingredient specialSoup = soup;


    // //printing
    // cout<<"The ingredients will now be printed:\n"
    // <<"-----STANDARD-----\n";
    // for(int i = 0; i < MAX; i++)
    // {
    //     cout<<"Ingredient "<<i+1<<": \t";
    //     cout<<"Name: "<<ings[i]->getName()<<" "
    //     <<"Danger Rating: "<<ings[i]->getDanger()<<endl;
    // }
    // cout<<"-----SPECIAL-----\n";
    // cout<<"Special 1 sould be ingredient 7.\n";
    // cout<<"special 1: "<<spI.getName()<<" "<<spI.getDanger()<<endl;
    // cout<<"Special 2 should be ingredient 2.\n";
    // cout<<"Special 2: "<<spII.getName()<<" "<<spII.getDanger()<<endl;
    // cout<<"Now for our soup and special soup:\n";
    // cout<<"Soup: "<<soup.getName()<<" "<<soup.getDanger()<<endl;
    // cout<<"Special Soup: "<<specialSoup.getName()<<" "<<specialSoup.getDanger()<<endl;


    // //deleting ingredients
    // cout<<"Goodbye ingredients!\n";
    // for(int i=0; i < MAX; i++)
    // {
    //     delete ings[i];
    // }
    // delete [] ings;
    // ings= NULL;


    //testing cauldron
    cout<<"\n Now lets make some cauldrons!\n";
    cout<<"Making the first cauldron\n";
    cauldron * cauld1 = new cauldron("list.txt", 8);
    cout<<"done.\n";

    cout<<"Making the second cauldron\n";
    cauldron cauld2("list.txt", 6);
    cout<<"done.\n";

    cout<<"Making a list of cauldrons\n";
    cauldron ** cauldList = new cauldron * [4];
    for(int i =0; i < 4; i++)
    {
        cauldList[i] = new cauldron("list.txt", 4);
    }
    cout<<"done.\n";

    cout<<"copying a cauldron\n";
    cauldron cauldCopy = cauldList[0];

    cout<<"Assigning a copy cauldron\n";
    cauldron cauldAssign("list.txt", 1);
    cauldAssign = cauld2;
    cout<<"done.\n";


    //print 1
    cout<<"\n-----PRINT 1-----\n";

    cout << "=================================================\n";

    cout<<"Cauld1: \n";
    cout<<"Max Ingredients: "<<cauld1->getMax()<<endl;
    cout<<"Number of Ingredients: "<<cauld1->getCurr()<<endl<<endl;

    cout<<"Ingredients: \n";
    cauld1->print();
    cout << endl;

    cout<<"List of Ingredients:\n";
    cauld1->listIngredients();

    cout << "=================================================\n";

    cout<<"Cauld2: \n";
    cout<<"Max Ingredients: "<<cauld2.getMax()<<endl;
    cout<<"Number of Ingredients: "<<cauld2.getCurr()<<endl<<endl;

    cout<<"Ingredients: \n";
    cauld2.print();
    cout << endl;

    cout<<"List of Ingredients:\n";
    cauld2.listIngredients();

    cout << "=================================================\n";

    cout<<"Cauld Assign (same as cauld2): \n";
    cout<<"Max Ingredients: "<<cauldAssign.getMax()<<endl;
    cout<<"Number of Ingredients: "<<cauldAssign.getCurr()<<endl<<endl;

    cout<<"Ingredients: \n";
    cauldAssign.print();
    cout << endl;

    cout<<"List of Ingredients:\n";
    cauldAssign.listIngredients();

    cout << "=================================================\n";

    //messing with the cauldrons
    cout<<"Messing with CauldList:\n\n";
    cauldList[1]->addIngredient("yeast", 4);
    cout<<"Ingredient added.\n";

    cauldList[2]->removeIngredient(3);
    cout<<"Ingredient removed.\n";

    cauldList[2]->removeIngredient(1);
    cout<<"Ingredient removed.\n";

    cauldList[2]->addIngredient("dandelion", 5);
    cout<<"Ingredient added.\n";

    string * list = new string[2];
    list[0] = "slimeball";
    list[1] ="goat hoof";

    cout << "\nIngredients to distill: \n";
    for (int i = 0; i < 2; i++)
        cout << list[i] << endl;
    cout << endl;

    cout << "************************************************\n";

    cout << cauld2.getMax() << endl;
    cout << cauld2.getCurr() << endl;
    cauld2.listIngredients();

    cout << "************************************************\n";

    cauldList[3]->distillPotion(cauld2, list, 2);
    cout << "Distilling potion\n";

    cout << "************************************************\n";

    cout << cauld2.getMax() << endl;
    cout << cauld2.getCurr() << endl;
    cauld2.listIngredients();

    cout << "************************************************\n";


    //printing values
    cout<<"-----PRINT 2-----\n";
    cout<<"Cauld List: \n";
    for(int i =0; i < 4; i++)
    {
        cout<<"Cauld:"<< i+1<<"\n";
        cout<<"Max Ingredients: "<<cauldList[i]->getMax()<<endl;
        cout<<"Number of Ingredients: "<<cauldList[i]->getCurr()<<endl;
        cout<<"Ingredients: \n";
        cauldList[i]->print();
        cout<<"List of Ingredients:\n";
        cauldList[i]->listIngredients();
        cout<<endl;
    }
    cout<<"Copy of cauld 0:\n";
    cout<<"Cauld Copy: \n";
    cout<<"Max Ingredients: "<<cauldCopy.getMax()<<endl;
    cout<<"Number of Ingredients: "<<cauldCopy.getCurr()<<endl;
    cout<<"Ingredients: \n";
    cauldCopy.print();
    cout<<"List of Ingredients:\n";
    cauldCopy.listIngredients();
    cout<<endl;


    //deleting cauldrons
    cout<<"goodbye cauldrons!\n";

    delete cauld1;
    cauld1 = NULL;

    for(int i =0; i < 4; i++)
    {
        delete cauldList[i];
        cout<<"done\n";
    }
    delete [] cauldList;
    cauldList = NULL;
    cout<<"done done\n";

    delete [] list;
    list = NULL;
    cout<<"done done done\n";

    return 0;
}