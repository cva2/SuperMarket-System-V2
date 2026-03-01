#include <iostream>
#include <string>
#include <cctype> // For  isdigit()
#include <limits> // For  cin.ignore() // cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std; 

//!  Function ProtoType

// For User
void menuItems();
void itemCount();
void payment(int);

// For Manager
void menuUsers();
void usernameCheck();
void passwordCheck();
void menuEditMenu();
void menuEditUsers();


//   Array For Usernames And Passwords
struct Sign {
  string usernames;
  string passwords;
  int rankManager;
};
int numUsers = 4;
Sign sign[10]
{
  {"anas", "0221", 2},
  {"anany",  "7412", 1},
  {"khalid", "1364", 1},
  {"tamer",  "1597", 1}
};

//   Array For Items
struct Items {
  int num;
  string name;
  double price;
};
int numItems = 30;
Items items[100]{ // {Number Of Product,  Name,  Price}
  {1,    "Tomato (1kg)",        15 },
  {2,    "Potato (1kg)",        18 },
  {3,    "Onion (1kg)",         20 },
  {4,    "Cucumber (1kg)",      12 },
  {5,    "Bread (Loaf)",         2 },
  {6,    "Milk (1L)",           28 },
  {7,    "Yogurt Cup",           7 },
  {8,    "Cheese Pack",         40 },
  {9,    "Eggs (30 pcs)",       145},
  {10,   "Butter 250g",         55 },
  {11,   "Rice 1kg",            25 },
  {12,   "Sugar 1kg",           30 },
  {13,   "Pasta 400g",          20 },
  {14,   "Tea Box",             35 },
  {15,   "Coffee Big Pack",     113},
  {16,   "Juice Box",           10 },
  {17,   "Water Bottle",         5 },
  {18,   "Chips Pack",          15 },
  {19,   "Chocolate Bar",       20 },
  {20,   "Soap Bar",            10 },
  {21,   "Shampoo",             55 },
  {22,   "Toothpaste",          22 },
  {23,   "Tuna Can",            22 },
  {24,   "Beans Can",           18 },
  {25,   "Ketchup Bottle",      30 },
  {26,   "Mayo Bottle",         35 },
  {27,   "Tissue Box",          20 },
  {28,   "Detergent Pack",      45 },
  {29,   "Salt Pack",            5 },
  {30,   "Black Pepper Pack",   10 }
  };

//   Global Variables

int counter1 = 0;
int counter2 = 0;
int User = 0; // => UserName Input Index
int counter4 = 0; // If Stop (Manager)
bool while1 = true;
bool while2 = true;
bool while3 = true;
//// For User
string name;
//// For Manager
string username1, pass1;




int main()
{
  int choice1;
  mainStart:
  cout << "\n\n"
          " ===============================================\n"
          "               S U P E R   M A R K E T\n"
          " ===============================================\n"
          "            E n t e r   T o   S t a r t\n";
  getchar();
  inchoice1:
  cout << "\n\nChoose From Main Menu:\n"
          " 1- System\n"
          " 2- User\n"
          " 3- Exit\n => ";
  cin >> choice1;
  cout << "------------------------------------------------\n";


  switch(choice1)
  {
    case 1:
    {
      int choice2;
      usernameCheck();
      passwordCheck();
      switch(sign[User].rankManager)
      {
        case 1:
        {
          int choice3;
          inchoice3: 
          cout << "\nYou Can Only Edit The Menu\n"
                  " 1- Continue\n"
                  " 2- Return To Menu\n => ";
          cin >> choice3;
          switch(choice3)
          {
            case 1: 
              menuEditMenu();
              break;
            case 2:
              goto mainStart;
            default:
              cout << "Incorrect Choice\n";
              goto inchoice3;
          }
          break;
        }
        case 2: 
        {
          int choice4;
          inchoice4:
          cout << "\nChoose What You Need To Do\n"
                  " 1- Edit Menu\n"
                  " 2- Edit Users\n"
                  " 3- Return To Main\n => ";
          cin >> choice4;
          switch(choice4)
          {
            case 1:
              menuEditMenu();
              break;
            
            case 2:
              menuEditUsers();
              break;

            case 3:
              goto mainStart;

            default:
              cout << "Incorrect Choice\n";
              goto inchoice4;
          }
          break;
        }
      }
      break;
    } 
    case 2:
    {
      int choice3;
      cout << " Please Enter Your Name\n => ";
      cin >> name;
      cout << "-----------------------------------------------\n"
              "- Hello " << name << " -\n------------------\n\n";
      
      cout << "Choose One:\n"
              " 1- Showing Menu\n"
              " 2- Return To Main\n => ";

      cin >> choice3;
      switch(choice3)
      {
        case 1:
          break;
        case 2:
          goto mainStart;
        default:
          cout << "Incorrect Choice\n";
          goto mainStart;
        
      }
      menuItems();
      itemCount();
      break;
    } 
    case 3:
    {
      cout << "\n\n"
            " ===============================================\n"
            "                T h a n k   Y o u\n"
            " ===============================================\n\n\n";
      return 0;
    }
    default:
      cout << "Incorrect Choice\n";
      goto inchoice1;
  }
  
  return 0;
}


void usernameCheck()
{
  int choice1;
  while(while1) // Enter User
  {
    cout << "Enter Your Username\n => ";
    cin >> username1;
    for(; User < numUsers; User++) // Check Users
    {
      if(sign[User].usernames == username1)
      {
        cout << "User Is Right\n------------------\n\n";
        counter2 = 0;
        return;
        
      }
    }
    cout << "Incorrect Username\n------------------\n";
    User = 0;
    counter2++;
    if(counter2 == 2)
    {
      inchoose1:
      cout << "\nFinal Try And I Will Kick You!\n"
              " 1- Continue\n"
              " 2- Return To Main\n"
              " 3- Exit With Your Honor\n => ";
      cin >> choice1;
      switch(choice1)
      {
        case 1:
          break;
        case 2:
          main();
          return;
        case 3:
          exit(0);
        default:
          cout << "Incorrect Choice\n";
          goto inchoose1;
      }
    } 
    else if(counter2 == 3)
    {
      counter2 = 0;
      exit(0);
    }
  }
}

void passwordCheck()
{
  int choice1;
  while(while2)
  {
    cout << "Now Enter Password\n => ";
    cin >> pass1;
    if(sign[User].passwords == pass1)
    {
      cout << "\n"
              " ===============================================\n"
              "          L o g i n   S u c c e s s f u l\n"
              " ===============================================\n";
      counter4 = 0;
      return;
    }
    else
    {
      cout << "Incorrect Username\n------------------\n";
      counter4++;
      if(counter4 == 2)
      {
        inchoose1:
        cout << "\nFinal Try And I Will Kick You!\n"
                " 1- Continue\n"
                " 2- Return To Main\n"
                " 3- Exit With Your Honor\n => ";
        cin >> choice1;
        switch(choice1)
        {
          case 1:
            break;
          case 2:
            main();
            return;
          case 3:
            exit(0);

          default:
            cout << "Incorrect Choice\n";
            goto inchoose1;
        }
      } 
      else if(counter4 == 3)
      {
      counter4 = 0;
      exit(0);
      }
    }
  }
}

void menuEditMenu()
{
  int choice1, choice2, choice3, choice4, choice5, choice6, choice7, choice8, choice9, choice10;
  inchoice1:
  cout << "-----------------------------------------------\n"
          "Choose Your Process:\n"
          " 1- Show Menu\n"    // Done
          " 2- Add Item\n"     // Done
          " 3- Update Item\n"  // Done
          " 4- Delete Item\n" // Done
          " 5- Back To Main\n => "; // Done
  cin >> choice1;
  switch(choice1)
  {
    case 1: // Show Items
    {
      menuItems();
      cout << "\n\n";
      goto inchoice1;
    } 
    case 2:
    {
      readd:

      items[numItems].num = numItems + 1; // For Cout Auto
      
      cout << "-----------------------------------------------\n"
              "Now Enter The Name\n => ";
      cin.ignore(1, '\n');
      getline(cin, items[numItems].name); // cin >> 
      while (isdigit(items[numItems].name[0])) // Check If He Start With Integet
      {
        cout << "Error: Can't Start With Number, ReEnter\n => ";
        getline(cin, items[numItems].name);
      }
      
      cout << "-----------------------------------------------\n"
              "Finally Enter The Price\n => ";
      cin >> items[numItems].price;
      numItems++;
      cout << "\n"
            " -----------------------------------------------\n"
            "               Item Added Successfully\n"
            " -----------------------------------------------\n\n";


      inchoice3:
      cout << "What Is Next:\n"
              " 1- Show Menu\n"
              " 2- Add Anther Item\n"
              " 3- Back To Main\n => ";
      cin >> choice3; 
      switch(choice3)
      {
        case 1:
          menuItems();
          inchoice4:
          cout << "-----------------------------------------------\n"
                  "After You See, Choose What You Need Now:\n"
                  " 1- Add Anther Item\n"
                  " 2- Back To Edit Menu\n"
                  " 3- Back To Main\n"
                  " 4- Exit\n => ";
          cin >> choice4;
          switch(choice4)
          {
            case 1: 
              goto readd;
            case 2:
              goto inchoice1;
            case 3:
              main();
              return;
            case 4:
              exit(0);
            default:
              cout << "Incorrect Choice\n";
              goto inchoice4;
          }
          break;
        case 2:
          goto readd;
        case 3:
          main();
          return;
        default:
          cout << "Incorrect Choice\n";
          goto inchoice3;
      }
      break;
    }
    case 3:
    {
      reupdate:
      inchoice5:
      cout << "-----------------------------------------------\n"
              "Choose The Type Of Change:\n"
              " 1- Change Name\n" // do
              " 2- Change Price\n => ";
      cin >> choice5;
      switch(choice5)
      {
        case 1:
        {
          int numItemChNa;
          upnumber:
          cout << "-----------------------------------------------\n" // have Error If I Write String Or Character
                  "Enter The Number Of Item\n => ";
          cin >> numItemChNa;
          if(numItemChNa > numItems)
          {
            cout << "You Have Only " << numItems << " !!\n";
            goto upnumber;
          }

          cout << "-----------------------------------------------\n"
                  "Now Enter Name Update\n => ";
          cin.ignore(1, '\n');
          getline(cin, items[numItemChNa - 1].name);
          while(isdigit(items[numItemChNa - 1].name[0]))
          {
            cout << "Error: Can't Start With Number, ReEnter\n => ";
            getline(cin, items[numItemChNa - 1].name);
          }

          inchoice6:
          cout << "-----------------------------------------------\n"
                  "What Is Next:\n"
                  " 1- Show Menu\n"
                  " 2- Update Anther Item\n"
                  " 3- Back To Main\n => ";
          cin >> choice6;
          switch(choice6)
          {
            case 1:
            {
              menuItems();
              inchoice7:
              cout << "-----------------------------------------------\n"
                      "After You See, Choose What You Need Now:\n"
                      " 1- Update Anther Item\n"
                      " 2- Back To Edit Menu\n"
                      " 3- Back To Main\n"
                      " 4- Exit\n => ";
              cin >> choice7;
              switch(choice7)
              {
                case 1:
                  goto reupdate;
                case 2:
                  goto inchoice1;
                case 3:
                  main();
                  return;
                case 4:
                  exit(0);
                  break;
                default:
                  cout << "Incorrect Choice\n";
                  goto inchoice7;

              }
            }
              break;
            case 2:
              goto reupdate;
            case 3:
              main();
              return;
            default:
              cout << "Incorrect Choice\n";
              goto inchoice6;
          }
          break;
        }
        case 2:
        {
          int numItemChPr;
          cout << "-----------------------------------------------\n"
                  "Enter The Number Of Item\n => ";
          cin >> numItemChPr;
          if(numItemChPr > numItems)
          {
            cout << "You Have Only " << numItems << " !!\n";
            goto upnumber;
          }
          cout << "-----------------------------------------------\n"
                  "Now Enter Price Update\n => ";
          cin >> items[numItemChPr - 1].price;
          
          inchoice8:
          cout << "-----------------------------------------------\n"
                  "And What Is Next:\n"
                  " 1- Show Menu\n"
                  " 2- Update Anther Item\n"
                  " 3- Back To Main\n => ";
          cin >> choice8;
          switch(choice8)
          {
            case 1:
              menuItems();
              inchoice9:
              cout << "\n\n"
                      "Ok, What About Now:\n"
                      " 1- Update Anther Item\n"
                      " 2- Back To Edit Menu\n"
                      " 3- Back To Main\n"
                      " 4- Exit\n => ";
              cin >> choice9;
              switch(choice9)
              {
                case 1:
                  goto reupdate;
                case 2:
                  goto inchoice1;
                case 3:
                  main();
                  return;
                case 4:
                  exit(0);
                default:
                  cout << "Incorrect Choice\n";
                  goto inchoice9;
              } 
              break;

            case 2:
              goto reupdate;
            case 3:
              main();
              return;
            default:
              cout << "Incorrect Choice\n";
              goto inchoice8;
          }
          break;
        }

        default:
          cout << "Incorrect Choice\n";
          goto inchoice5;

      }
      break;
    }
    case 4:
    {
      int index;
      redelete:
      cout << "-----------------------------------------------\n"
              "Enter Number Of Item You Need To Delete\n => ";
      cin >> index;

      cout << "The Item You Will Delete Is:\n";
      
      { // Show The Item
        cout << "\n-----------------------------------------------\n";
        // Number And Name
        if(items[index - 1].num < 10) 
          cout << "    " << items[index - 1].num << " | " << items[index - 1].name;
        else if(items[index - 1].num < 100)
          cout << "   " << items[index - 1].num << " | " << items[index - 1].name;
        else 
          cout << "  " << items[index - 1].num << " | " << items[index - 1].name;

        // Spaces After Name
        int space = 30 - items[index - 1].name.length(); 
        for(int s = 0; s < space; s++)
          cout << " ";

        // Rest ( Price )
        cout << "|";
        if(items[index - 1].price < 10)
          cout << "   " << items[index - 1].price << " EGP\n";
        else if(items[index - 1].price < 100)
          cout << "  " << items[index - 1].price << " EGP\n";
        else
          cout << " " << items[index - 1].price << " EGP\n";
          
        cout << "-----------------------------------------------\n";
        
      }

      // Deleting Process
      for(int i = index; i < numItems; i++)
      {
        items[i - 1].num   = items[i].num - 1;
        items[i - 1].name  = items[i].name;
        items[i - 1].price = items[i].price;
      }
      numItems--;

      cout << "\n-----------------------------------------------\n"
              "              Item Deleted Successfully\n"
              "-----------------------------------------------\n\n";

      menuItems();
      inchoice10:
      cout << "-----------------------------------------------\n"
              "Now What You Need To Do:\n"
              " 1- Delete Anther Item\n"
              " 2- Return To Editing Menu\n"
              " 3- Return To Main\n"
              " 4- Exit\n => ";
      cin >> choice10;
      switch(choice10)
      {
        case 1:
          goto redelete;
        case 2:
          goto inchoice1;
        case 3:
          main();
          return;
        case 4:
          exit(0);
        default:
          cout << "Incorrect Choice\n";
          goto inchoice10;
      }
      break;
    }
    case 5:
    {
      main();
      return;
    }
    default:
      cout << "Incorrect Choice\n";
      goto inchoice1;
  }
}

void menuEditUsers()
{
  int achoice1, achoice2, achoice3, achoice4, achoice5;
  inchoice1:
  cout << "\n-----------------------------------------------\n"
          "Choose Your Process\n"
          " 1- Show Users\n"
          " 2- Add Employee\n"
          " 3- Promotion Employee\n"
          " 4- Kick Employee\n"
          " 5- Back To Main\n => ";
  cin >> achoice1;
  switch(achoice1)
  {
    case 1: // Show Users
    {
      menuUsers();
      cout << "\n\n";
      goto inchoice1;
    }
    case 2: // Add Employee 
    {
      readd:
      
      cout << "-----------------------------------------------\n"
              "Enter New Username\n => ";
      cin >> sign[numUsers].usernames;

      cout << "Enter Password\n => ";
      cin >> sign[numUsers].passwords;

      cout << "Enter Rank\n"
              " 1- Employee\n"
              " 2- Manager\n => ";
      cin >> sign[numUsers].rankManager;

      rerank:
      if(sign[numUsers].rankManager != 1 
      && sign[numUsers].rankManager != 2)
      {
        cout << "Incorrect Rank\n";
        goto rerank;
      }

      numUsers++;

      cout << "\n"
              "-----------------------------------------------\n"
              "             Employee Added Successfully\n"
              "-----------------------------------------------\n";

      inchoice2:
      cout << "What Is Next\n"
              " 1- Show Employees\n"
              " 2- Add Anther Employee\n"
              " 3- Back To Main\n => ";
      cin >> achoice2;
      switch(achoice2)
      {
        case 1:
          menuUsers();
          inchoice3:
          cout << "-----------------------------------------------\n"
                  "Choose What You Need Now:\n"
                  " 1- Add Anther Employee\n"
                  " 2- Back To Edit Menu\n"
                  " 3- Back To Main\n"
                  " 4- Exit\n => ";
          cin >> achoice3;
          switch(achoice3)
          {
            case 1:
              goto readd;
            case 2:
              goto inchoice1;
            case 3:
              main();
              return;
            case 4:
              exit(0);
            default:
              cout << "Incorrect Choice\n";
              goto inchoice3;
          }
          break;
        case 2:
          goto readd;
          break;
        case 3:
          main();
          return;
        default:
          cout << "Incorrect Choice\n";
          goto inchoice2;
      }
      break;
    }
    case 3: // Promotion
    {
      inindex:
      int index, x;
      string user1;
      cout << "-----------------------------------------------\n"
              "Enter Employee User To Promote\n => ";
      cin >> user1;
      for(x = 0; x < numUsers; x++)
        if(sign[x].usernames == user1)
          index = x;

      inindex1:
      if(index > numUsers)
      {
        cout << "Incorrect Number\n";
        goto inindex1;
      }
      if(sign[index].rankManager == 2)
      {
        cout << "Already Manager!\n";
        goto inindex1;
      }
      else
      {
        sign[index].rankManager++;
        cout << "\n-----------------------------------------------\n"
                "             " << sign[index].usernames << " Promoted To Manager\n"
                "-----------------------------------------------\n\n";
      }

      inchoice4:
      cout << "What About Now:\n"
              " 1- Back To Main\n"
              " 2- Exit\n => ";
      cin >> achoice4;
      switch(achoice4)
      {
        case 1:
          main();
          return;
        case 2:
          exit(0);
        default:
          cout << "Incorrect Choice\n";
          goto inchoice4;
      }

    }
    case 4: // Kick
    {
      int index, i;
      redelete:
      string user2;
      cout << "-----------------------------------------------\n"
              "Enter Employee User To Kick\n => ";
      cin >> user2;
      for(i = 0; i < numUsers; i++)
        if(sign[i].usernames == user2)
          index = i;

      inindex2:
      if(index > numUsers)
      {
        cout << "Incorrect Number\n";
        goto inindex2;
      }
      if(sign[index].rankManager == 2)
      {
        cout << "Kick Manager!, HgHgHgHg\n";
        goto inindex2;
      }

      for(int k = index; k < numUsers; k++)
      {
        sign[k].usernames   = sign[k + 1].usernames;
        sign[k].passwords   = sign[k + 1].passwords;
        sign[k].rankManager = sign[k + 1].rankManager;
      }
      numUsers--;

      cout << "\n-----------------------------------------------\n"
              "             Employee Deleted Successfully\n"
              "-----------------------------------------------\n\n";

      menuUsers();
      inchoice5:
      cout << "\n\n-----------------------------------------------\n"
              "Now What You Need To Do:\n"
              " 1- Delete Anther Employee\n"
              " 2- Return To Editing Menu\n"
              " 3- Return To Main\n"
              " 4- Exit\n => ";
      cin >> achoice5;
      switch(achoice5)
      {
        case 1:
          goto redelete;
        case 2:
          goto inchoice1;
        case 3:
          main();
          return;
        case 4:
          exit(0);
        default:
          cout << "Incorrect Choice\n";
          goto inchoice5;
      }
      break;
    }
    case 5: // Main
    {
      main();
      return;
    }
    default:
      cout << "Incorrect Choice\n";
      goto inchoice1;
  }
}

void menuItems()
{
  
  cout << "\n"
          "  ===============================================\n"
          "          S U P E R   M A R K E T   M E N U\n"
          "  ===============================================\n"
          "   No | Name                          | Price\n"
          "  -----------------------------------------------\n";
  
  // Print Items
  for(int i = 0; i < numItems; i++) 
  {
    // Number And Name
    if(items[i].num < 10)
      cout << "    " << items[i].num << " | " << items[i].name;
    else if(items[i].num < 100)
      cout << "   " << items[i].num << " | " << items[i].name;
    else 
      cout << "  " << items[i].num << " | " << items[i].name;
    
    // Spaces After Name
    int space = 30 - items[i].name.length();
    for(int s = 0; s < space; s++)
      cout << " ";
    
    // Rest ( Price )
    cout << "|";
    if(items[i].price < 10)
      cout << "   " << items[i].price << " EGP\n";
    else if(items[i].price < 100)
      cout << "  " << items[i].price << " EGP\n";
    else
      cout << " " << items[i].price << " EGP\n";
    
  }
  
  cout << "  ===============================================\n"
          "          S U P E R   M A R K E T   M E N U\n"
          "  ===============================================\n";

  return;
}

void menuUsers()
{
  cout << "\n"
          "===============================================\n"
          "                E m p l o y e e s\n"
          "===============================================\n"
          " No | Username        | Password   | Rank\n"
          "-----------------------------------------------\n";
  for(int i = 0; i < numUsers; i++)
  {
    cout << "  " << i + 1 << " | "
         << sign[i].usernames;

    int spaceUser = 15 - sign[i].usernames.length();
    for(int s = 0; s < spaceUser; s++)
      cout << " ";
      
    cout << " | " << sign[i].passwords;
    
    int spacePass = 10 - sign[i].passwords.length();
    for(int s = 0; s < spacePass; s++)
      cout << " ";

    cout << " | ";
    
    if(sign[i].rankManager == 1)
      cout << "Employee\n";
    if(sign[i].rankManager == 2)
      cout << "Manager\n";
  }
    
    cout << "===============================================\n"
            "                E m p l o y e e s\n"
            "===============================================";
}

void itemCount() // Count The Price 
{
  int item, mount, totCost = 0;
  cout << "\n\nPlease Enter The Mount Of Items You Need\n";
  mountBov:
  cout << " => ";
  cin >> mount;
  
  if(mount > 30) // Mount Above
  {
    if(counter1 == 1)
    {
      cout << "Fuck You Pro\n\n";
      counter1 = 0;
      exit(0);
    }
    else
    {
      cout << "Are Joking.. Final Try Ok!\n";
      counter1++;
      goto mountBov;
    }
  }
  cout << "Now Choose " << mount << " Item Using No\n\n";
  
  for(int i = 0; i < mount; i++) // Mount Of Items And Cost
  {
    itemBov:
    cout << i + 1 << " - \n";
    cout << "Item  => ";
    cin >> item;
    if(item > numItems)
    {
      cout << " -- !seriously! --\n\n";
      goto itemBov;
    }
    cout << "Price => " << items[item - 1].price 
         << "\n-----------------------------------------------\n";
    totCost += items[item - 1].price;
  }
  cout << "Total Cost is: " << totCost;
  
  int choice1;
  inchoose1:
  cout << "\n\nPlease Proceed To Pay Your Bill\n"
          " 1- Proceed\n"
          " 2- Cancel And Return To Menu\n"
          " 3- Exit\n => ";
  
  cin >> choice1;
  switch(choice1)
  {
    case 1:
    {
      payment(totCost);
      break;
    }
    case 2:
    {
      menuItems();
      return;
    }
    case 3:
    {
      cout << "\n\n"
              " ===============================================\n"
              "                  Thank You " << name << "\n"
              " ===============================================\n";
      exit(0);
    }
    default:
      cout << "Incorrect Choice\n";
      goto inchoose1;
  }
}

void payment(int cost) // The Bill 
{
  int cash1, cash2, rest, rest2;
  cout << "\nEnter Cash Money Please\n => ";
  cin >> cash1;
  recheck: // Is A Label (Check Point)

  if(cash1 >= cost) // Calculate Rest
    rest = cash1 - cost;
  else // Calculate Change
  {
    rest2 = cost - cash1;
    cash2 = 0;
    cout << "\nNeeding More Money.. ( Adding )\n => ";
    cout << "Change: " << rest2 << endl;
    cin >> cash2;
    cash1 += cash2;
    goto recheck; // Back To The Check Point
  }
  
  cout << "Rest Is => " << rest << "\n";
  while(rest > 0) // Rest Of Money
  {
    if(rest >= 200)
    {
      cout << "200 EGP\n";
      rest -= 200;
    }
    else if(rest >= 100)
    {
      cout << "100 EGP\n";
      rest -= 100;
    }
    else if(rest >= 50)
    {
      cout << "50 EGP\n";
      rest -= 50;
    }
    else if(rest >= 20)
    {
      cout << "20 EGP\n";
      rest -= 20;
    }
    else if(rest >= 10)
    {
      cout << "10 EGP\n";
      rest -= 10;
    }
    else if(rest >= 5)
    {
      cout << "5 EGP\n";
      rest -= 5;
    }
    else if(rest >= 1)
    {
      cout << "1 EGP\n";
      rest -= 1;
    }
    
  }

  if(rest == 0) // Buy Again Or Go
  {
    int choice1;
    reenter1:
    cout << "\n\n"
            " 1- Buy Again\n"
            " 2- Exit\n => ";
    
    cin >> choice1;
    switch(choice1)
    {
      case 1:
      {
        menuItems();
        itemCount();
      }
      case 2:
      {
        cout << "\n\n"
                " ===============================================\n"
                "                  Thank You " << name << "\n"
                " ===============================================\n";
        exit(0);
      }
      default:
        cout << "Incorrect Choice\n";
        goto reenter1; 
    } 
  }
}


































//!                                     ===============================================      
//!                                                     E m p l o y e e s
//!                                     ===============================================      
//!                                      No | Username        | Password   | Rank
//!                                     -----------------------------------------------      
//!                                       1 | anas            | 0221       | Manager
//!                                       2 | anany           | 7412       | Employee        
//!                                       3 | khalid          | 1364       | Employee
//!                                       4 | tamer           | 1597       | Employee
//!                                     ===============================================      
//!                                                     E m p l o y e e s
//!                                     ===============================================      
  





























