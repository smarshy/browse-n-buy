#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>        //for delay and sleep function
#include<graphics.h>   //for textcolor & textbackground

int flag=0;
long int sum=0;

class consumer
{
    char cname[20];
    char adress[20];
    public:
    int choi,n,cno;

    //FUNCTION TO ENTER THE VALUES
    void entry() {
        clrscr();
        cout<<"\n\n\n\t\tFirst Enter the details please";
        cout<<"\n\n\n\nConsumer ID     :"<<"\t";
        cin>>cno;
        cout<<"\n\nConsumer name   :"<<"\t";
        gets(cname);
        cout<<"\n\nConsumer Address:"<<"\t";
        gets(adress);
    }

    //FUNCTION TO DISPLAY THE VALUES
    void display() {
        cout<<"\n\n\n\t\t\tYour details are as follows\n\n \n";
        cout<<"\n\n\n\nConsumer ID     :"<<"\t"<<cno;
        cout<<"\n\nConsumer name   :"<<"\t";
        puts(cname);
        cout<<"\n\nConsumer Address:"<<"\t";
        puts(adress);
    }
}c1;  


void write()
{
    char ch;
    fstream f1;
    c1.entry();
    f1.open("MAIN.DAT",ios::out|ios::app|ios::binary);
    cout<<"\n\n\tDO you want to save the record(y/n)\t";
    cin>>ch;
    if(ch=='y')
    {
        f1.write((char*)&c1,sizeof(c1));
    }
    f1.close();
}


//FUNCTION TO READ THE VALUES
void read(){
    fstream f1;
    f1.open("MAIN.DAT",ios::in|ios::binary);
    f1.seekg(0);
    while(!f1.eof()){
        f1.read((char*)&c1,sizeof(c1));
        c1.display();
        if(f1.eof())
        {
            cout<<"\n\n   End of the file reached\n\n";
        }
    }
        f1.close();
}

//FUNCTION FOR SEARCHING RECORDS
void search(){
    int pos;
    int rn;
    char found='n';
    ifstream f1;
    f1.open("MAIN.DAT",ios::in);
    cout<<"\n\n Enter Customer ID you want to SEARCH :\t";
    cin>>rn;
    while(!f1.eof()){
        pos=f1.tellg();
        f1.read((char*)&c1,sizeof(c1));
        if(c1.cno==rn){
            f1.seekg(pos);
            c1.display();
            found='y';
            break;
        }
    }
    if(found=='n')
        cout<<"\n\n\tRECORD NOT FOUND!!!!!!!!!!!!!\n"<<endl;
    f1.close();
}

void mani(char nom1[],int pr){
  fstream fout;
  fout.open("MOVIE.DAT",ios::in|ios::out|ios::app|ios::trunc);
  cout<<"\n\n\n\n\nWhat do you want to do??(Press 1 or 2)\n\n1.Buy movie\n\n2.Exit\n\n";
  cin>>c1.choi;
  if(c1.choi==1){
    cout<<"\n\nHow many copies do you want?\n\n";
    cin>>c1.n;
    if(c1.n!=0){
      flag=1;
      fout<<nom1<<pr<<"\t         "<<c1.n<<"\t            "<<c1.n*pr<<"\n\n";
      for(int i=0;i<c1.n;i++)
        ::sum+=pr;
    }
    else
      if(c1.choi==2){

      }
      else{
        cout<<"\n\nPlease select valid option!!!!\n\n";
      }
    }
}

void main()

{

clrscr();
int choice,opt,price,ch4,che;//declarations of variables
char c,ch1,ch2,ch3,ch5,ch6;
char line[1000],name[75],nom[200];


cout<<"\n\n\n\n\t\t\t\t####################\n";
cout<<"\n\n\n\n\t\t\t\t#   MOVIE MANIA    #\n";
cout<<"\n\n\n\n\t\t\t\t####################\n\n";

cout<<"  WELCOME!!!!!!!FEEL FREE TO NAVIGATE OUR DVD STORE AND CHOOSE FROM OUR \n\nCOLLECTION OF 20 CRITICALLY ACCLAIMED MOVIES OF ALL TIME-BOTH ENGLISH AND HINDI\n\n\n";
cout<<"\n\nPress any key to continue";


getch();
clrscr();

gotoxy(32,13);
textcolor(LIGHTGREEN);
cputs("********************");
gotoxy(32,15);
cputs("LOADING OUR PROJECT");
gotoxy(32,17);
cputs("********************");
gotoxy(32,20);
textcolor(MAGENTA+BLINK);
cputs("PLEASE WAIT.........");
textcolor(RED+GREEN);
delay(500);
gotoxy(32,35);
cputs("10 % completed..");
delay(500);
gotoxy(32,35);
cputs("20 % completed...");
delay(500);
gotoxy(32,35);
cputs("30 % completed....");
delay(500);
gotoxy(32,35);
cputs("40 % completed.....");
delay(500);
gotoxy(32,35);
cputs("50 % completed......");
delay(500);
gotoxy(32,35);
cputs("60 % completed.......");
delay(500);
gotoxy(32,35);
cputs("70 % completed........");
delay(500);
gotoxy(32,35);
cputs("80 % completed.........");
delay(500);
gotoxy(32,35);
cputs("90 % completed..........");
delay(500);
gotoxy(32,35);
cputs("100 % completed...........");
delay(500);

start:;

clrscr();

fstream fout;
fout.open("MOVIE.DAT",ios::in|ios::out|ios::app);   //opening a file so that details of purchase can be saved

fstream f1;
f1.open("MAIN.DAT",ios::in | ios::out | ios::binary|ios::app);
if(!fout||!f1){
    cout<<"\n\nFILE CANNOT BE ACCESSED\n\n";
}

textcolor(GREEN);
cout<<"\n\t\t\t    ^^^^^^^^^^^^^^^^^^^^^^^^^^^";
cout<<"\n\t\t\t    !=========================!\n";
cout<<"\n\t\t\t    !****   MOVIE MANIA   ****!\n";
cout<<"\n\t\t\t    !=========================!";
cout<<"\n\t\t\t    ^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n";
cout<<"  \t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
cout<<"\n\n\t\t\t*     1.BROWSE THROUGH THE MOVIES *";
cout<<"\n\n\t\t\t*     2.DETAILS                   *";
cout<<"\n\n\t\t\t*     3.RETRIEVE A RECORD         *";
cout<<"\n\n\t\t\t*     4.DISPLAY ALL RECORDS       *";
cout<<"\n\n\t\t\t*     5.EXIT                      *\n\n\n";
cout<<"\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
cout<<"\n\n\n\n\t Enter your choice :\t";

cin>>che;

if(che==1) {
    clrscr();
    write();
    clrscr();

    label:do {
        cout<<"\n\n\n\nWhich movie collection do you want to see?????(press 1 or 2)";
        cout<<"\n\n1.English\n\n";
        cout<<"2.Hindi\n\n";
        cin>>opt;
        clrscr();

        if(opt==1) {
            do {
                cout<<"\n\n\n\n\t\t\t\tENGLISH COLLECTION\n\n";
                cout<<"\n\n\t1.The Boy in Striped Pyjamas            11.The Matrix\n\n";
                cout<<"\t2.Avatar                                12.V For Vendetta\n\n";
                cout<<"\t3.Da Vinci Code                         13.Casablanca\n\n";
                cout<<"\t4.The Godfather                         14.Inception\n\n";
                cout<<"\t5.Murder on The Orient Express          15.Citizen Kane\n\n";
                cout<<"\t6.Double Jeopardy                       16.Extra Terrestial\n\n";
                cout<<"\t7.The Dark Knight                       17.The Shawshank Redemption\n\n";
                cout<<"\t8.Forrest Gump                          18.Jaws\n\n";
                cout<<"\t9.Titanic                               19.Schindler's List\n\n";
                cout<<"\t10.Paranormal Activity                  20.Sixth Sense\n\n";
                cout<<"\n\n\tPlease select a movie from the given choices!!!\t\n\n\t(Press respective serial no. to select the corresponding movie)\n\n";
                cin>>choice;
                clrscr();
                switch(choice) { 

                    case 1: do { 
                        cout<<"\n\n\t\t\tTHE BOY IN THE STRIPED PYJAMAS\n\n\n\t\t      94 min  -  Drama | Thriller | War\n\n\nSet during World War II, a story seen through the innocent eyes of Bruno,the\n\neight-year-old son of the commandant at a concentration camp,whose forbidden \n\nfriendship with a Jewish boy on the other side of the camp fence has startling \n\nand unexpected consequences.\n\n\n    Year OF RELEASE:2008                            IMDB RATING:7.8/10\n\n    Price=Rs 299";
                        strcpy(nom,"THE BOY IN STRIPED PYJAMAS     ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 2:do {
                        cout<<"\n\n\t\t\t\t  AVATAR\n\n\n\t\t162 min  -  Action | Adventure | Fantasy | Sci-Fi\n\n\nA paraplegic marine dispatched to the moon Pandora on a unique mission becomes\n\ntorn between following his orders and protecting the world he feels is his home.\n\n\n    Year OF RELEASE:2009                           IMDB RATING:8.3/10\n\n    Price=Rs 599";
                        strcpy(nom,"AVATAR                         ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 3:do {
                        cout<<"\n\n\t\t\t\tDA VINCI CODE\n\n\n\t\t\t149 min  -  Mystery | Thriller  \n\n\nA murder inside the Louvre and clues in Da Vinci paintings lead to the discovery \n\nof a religious mystery protected by a secret society for two thousand years. \n\n\n\n    Year OF RELEASE:2006                           IMDB RATING:6.4/10\n\n    Price=Rs 599";
                        strcpy(nom,"DA VINCI CODE                  ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 4:do {
                        cout<<"\n\n\t\t\t\tTHE GODFATHER\n\n\n\t\t    175 min  -  Crime | Drama | Thriller \n\n\n  The aging patriarch of an organized crime dynasty transfers control of his \n\n  clandestine empire to his reluctant son.\n\n\n    Year OF RELEASE:1972                           IMDB RATING:9.1/10\n\n    Price=Rs 199";
                        strcpy(nom,"THE GODFATHER                  ");
                        price=199;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 5:do {
                        cout<<"\n\n\t\t\tMURDER ON THE ORIENT EXPRESS\n\n\n\t\t  128 min  -  Crime | Mystery | Thriller\n\n\n In 1935, when his train is stopped by deep snow, detective Hercule Poirot is \n\n  called on to solve a murder that occurred in his car the night before.\n\n\n    Year OF RELEASE:1974                          IMDB RATING:7.5/10\n\n    Price=Rs 99";
                        strcpy(nom,"MURDER ON THE ORIENT EXPRESS   ");
                        price=99;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 6:do {
                        cout<<"\n\n\t\t\t\tDOUBLE JEOPARDY\n\n\n\t\t105 min  -  Crime | Drama | Mystery | Thriller\n\n\nA woman framed for her husband's murder suspects he is still alive; as she has \n\nalready been tried for the crime,she can't be re-prosecuted if she finds and \n\nkills him.\n\n\n    Year OF RELEASE:1999                          IMDB RATING:6.0/10\n\n    Price=Rs 69";
                        strcpy(nom,"DOUBLE JEOPARDY                ");
                        price=69;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 7:do {
                        cout<<"\n\n\t\t\t\tTHE DARK KNIGHT\n\n\n\t\t152 min  -  Action | Crime | Thriller\n\n\n Batman, Gordon and Harvey Dent are forced to deal with the chaos unleashed by \n\n an anarchist mastermind known only as the Joker, as it drives each of them to \n\n their limits. \n\n\n    Year OF RELEASE:2008                          IMDB RATING:8.9/10 \n\n    Price=Rs 599";
                        strcpy(nom,"THE DARK KNIGHT                ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 8:do {
                        cout<<"\n\n\t\t\t\tFORREST GUMP\n\n\n\t\t\t142 min  -  Drama | Romance \n\n\n\nForrest Gump, while not intelligent,has accidentally been present at many\n\n\nhistoric moments.However this is all irrelevant to Forrest who can only think of\n\nhis childhood sweetheart Jenny.in the end all he wants to prove is that anyone\n\n\ncan love anyone.\n\n\n\n    Year OF RELEASE:1994                          IMDB RATING:8.6/10\n\n    Price=Rs 299";
                        strcpy(nom,"FORREST GUMP                   ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 9:do {
                        cout<<"\n\n\t\t\t\t\tTITANIC\n\n\n\t\t     194 min  -  Drama | History | Romance \n\n\n Fictional romantic tale of a rich girl and poor boy who meet on the ill-fated \n\n voyage of the 'unsinkable' ship. \n\n\n    Year OF RELEASE:1997                          IMDB RATING:7.4/10 \n\n    Price=Rs 999";
                        strcpy(nom,"TITANIC                        ");
                        price=999;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 10:do {
                        cout<<"\n\n\t\t\t\tPARANORMAL ACTIVITY\n\n\n\t\t\t   86 min  -  Horror | Thriller \n\n\n\nAfter a young, middle class couple moves into a suburban 'starter' tract house, \n\nthey become increasingly disturbed by a presence that may or may not be somehow \n\ndemonic but is certainly most active in the middle of the night. Especially when \n\nthey sleep. Or try to.\n\n\n\n    Year OF RELEASE:2007                          IMDB RATING:6.7/10\n\n    Price=Rs 299";
                        strcpy(nom,"PARANORMAL ACTIVITY            ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 11:do {
                        cout<<"\n\n\t\t\t\tTHE MATRIX\n\n\n\t\t136 min  -  Action | Adventure | Sci-Fi \n\n\n A computer hacker learns from mysterious rebels about the true nature of his \n\n reality and his role in the war against its controllers.\n\n\n    Year OF RELEASE:1999                          IMDB RATING:8.7/10\n\n    Price=Rs 599";
                        strcpy(nom,"THE MATRIX                     ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 12:do {
                        cout<<"\n\n\t\t\t\tV FOR VENDETTA\n\n\n\t\t   132 min  -  Action | Sci-Fi | Thriller \n\n\nThe futuristic tale unfolds in a Great Britain.A freedom fighter known as V uses \n\nterrorist tactics to fight the oppressive society. He rescues a young woman from \n\nthe secret police,and she becomes his unlikely ally.\n\n\n    Year OF RELEASE:2006                          IMDB RATING:8.2/10\n\n    Price=Rs 299";
                        strcpy(nom,"V FOR VENDETTA                 ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 13:do {
                        cout<<"\n\n\t\t\t\t CASABLANCA\n\n\n\t\t\t102 min  -  Drama | Romance | War \n\n\n Set in unoccupied Africa during the early days of World War II: An American \n\n expatriate meets a former lover, with unforeseen complications.\n\n\n    Year OF RELEASE:1942                         IMDB RATING:8.8/10\n\n    Price=Rs 299 ";
                        strcpy(nom,"CASABLANCA                     ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 14:do {
                        cout<<"\n\n\t\t\t\tINCEPTION\n\n\n\t\t148 min  -  Action | Crime | Mystery | Sci-Fi\n\n\n  Dom Cobb is a skilled thief, the absolute best in the dangerous art of \n\n  extraction, an ability that cost him everything he ever loved. Now Cobb is\n\n  being offered a chance at redemption:but only if he can accomplish the \n\n  impossible-inception. The task is not to steal an idea but to plant one.\n\n\n    Year OF RELEASE:2010                        IMDB RATING:9/10\n\n    Price=Rs 799";
                        strcpy(nom,"INCEPTION                     ");
                        price=799;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 15:do {
                        cout<<"\n\n\t\t\t\tCITIZEN KANE\n\n\n\t\t\t119 min  -  Drama | Mystery\n\n\n\nFollowing the death of a publishing tycoon, news reporters scramble to discover \n\nthe meaning of his final utterance.\n\n\n\n    Year OF RELEASE:1941                        IMDB RATING:8.6/10\n\n    Price=Rs 599";
                        strcpy(nom,"CITIZEN KANE                   ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 16:do {
                        cout<<"\n\n\t\t\t\tEXTRA TERRESTRIAL\n\n\n\t\t115 min  -  Adventure | Drama | Family | Fantasy \n\n\n\nElliot is a normal boy, until one day, when he meets a little lost alien. Elliot \n\ndecides to keep the alien,and works with him in trying to find him a way to get \n\nback home. \n\n\n\n    Year OF RELEASE:1982                        IMDB RATING:7.9/10\n\n    Price=Rs 299";
                        strcpy(nom,"EXTRA TERRESTRIAL              ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 17:do {
                        cout<<"\n\n\t\t\t  SHAWSHANK REDEMPTION\n\n\n\t\t\t142 min  -  Crime | Drama   \n\n\nTwo imprisoned men bond over a number of years, finding solace and eventual \n\nredemption through acts of common decency.\n\n\n     Year OF RELEASE:1994                       IMDB RATING:9.2/10\n\n    Price=Rs 599";
                        strcpy(nom,"SHAWSHANK REDEMPTION           ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 18:do {
                        cout<<"\n\n\t\t\t\t       JAWS\n\n\n\t\t\t\t124 min  -  Thriller\n\n\n\nWhen a gigantic great white shark begins to menace the small island community of \n\nAmity, a police chief, a marine scientist and grizzled fisherman set out to stop \n\nit. \n\n\n\n    Year OF RELEASE:1975                       IMDB RATING:8.3/10\n\n    Price=Rs 199";
                        strcpy(nom,"JAWS                           ");
                        price=199;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 19:do {
                        cout<<"\n\n\t\t\t\tSCHINDLER'S LIST\n\n\n\t\t195 min  -  Biography | Drama | History | War\n\n\n In Poland during World War II, Oskar Schindler gradually becomes concerned for \n\n his Jewish workforce after witnessing their persecution by the Nazis. \n\n\n    Year OF RELEASE:1993                       IMDB RATING:8.9/10\n\n    Price=Rs 199";
                        strcpy(nom,"SCHINDLER'S LIST               ");
                        price=199;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 20:do {
                        cout<<"\n\n\t\t\t\tSIXTH SENSE\n\n\n\t\t107 min  -  Drama | Mystery | Thriller\n\n\n\nA boy who communicates with spirits that don't know they're dead seeks the help \n\nof a disheartened child psychologist.\n\n\n\n    Year OF RELEASE:1999                       IMDB RATING:8.2/10\n\n    Price=Rs 199";
                        strcpy(nom,"SIXTH SENSE                    ");
                        price=199;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    default: cout<<"\n\nKindly select an option from the list....\n\n";
                }

                cout<<"\n\nDo you want to go back to the english list???\n\n(Press Y for yes or any other character for no)\n\n";
                cin>>ch2;
                clrscr();
            }while((ch2=='Y')||(ch2=='y'));
        }
        else if(opt==2) {
            do {
                cout<<"\n\n\n\n\t\t\t\tHINDI COLLECTION\n\n";
                cout<<"\n\n\t1.Lagaan                                11.Mother India\n\n";
                cout<<"\t2.Taare Zameen Par                      12.Tere Bin Laden\n\n";
                cout<<"\t3.3 Idiots                              13.Dil Chahta Hai\n\n";
                cout<<"\t4.A Wednesday                           14.Salaam Bombay!\n\n";
                cout<<"\t5.Rajneeti                              15.Lakshya\n\n";
                cout<<"\t6.Chak De India!                        16.Guru\n\n";
                cout<<"\t7.Aamir                                 17.Black\n\n";
                cout<<"\t8.Black Friday                          18.Sholay\n\n";
                cout<<"\t9.Rang De Basanti                       19.Swades: We, the People\n\n";
                cout<<"\t10.Mughal-E-Azam                        20.Andaz Apna Apna\n\n";
                cout<<"\n\n\tPlease select a movie from the given choices!!!\t\n\n\t(Press respective serial no. to select the corresponding movie)\n\n";
                cin>>choice;
                clrscr();

                switch(choice) {       

                    case 1:do {
                        cout<<"\n\n\t\t\tLAGAAN-ONCE UPON A TIME IN INDIA\n\n\n\t\t     224 min  -  Drama | Musical | Romance\n\n\n\nThe people of a small village in Victorian India stake their future on a game of \n\ncricket against their ruthless British rulers... \n\n\n\n    Year OF RELEASE:2001                       IMDB RATING:8.1/10 \n\n    Price=Rs 599";
                        strcpy(nom,"LAGAAN                         ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 2:do {
                        cout<<"\n\n\t\t\t\tTAARE ZAMEEN PAR\n\n\n\t\t\t\t65 min  -  Drama \n\n\n\nAn art teacher, Ram Shankar Nikumbh teaches at a local boarding school and \n\nthinks that every child is special.All the children respond to him with joy, \n\nall except a small boy  named Ishaan Awasthi. Nikumbh soon finds out that he is \nunhappy about something and attempts to help him.\n\n\n\n    Year OF RELEASE:2007                       IMDB RATING:8.2/10\n\n    Price=Rs 299";
                        strcpy(nom,"TAARE ZAMEEN PAR               ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 3:do {
                        cout<<"\n\n\t\t\t\t 3 IDIOTS\n\n\n\t\t    160 min  -  Comedy | Drama | Romance \n\n\n\nTwo friends embark on a quest for a lost buddy. On this journey, they encounter \n\na long forgotten bet,a wedding they must crash,and a funeral that goes \n\n\nimpossibly out of control...\n\n\n\n    Year OF RELEASE:2009                       IMDB RATING:8.3/10 \n\n    Price=Rs 599";
                        strcpy(nom,"3 IDIOTS                       ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 4:do {
                        cout<<"\n\n\t\t\t\tA WEDNESDAY\n\n\n\t\t\t 104 min  -  Drama | Thriller \n\n\n\nA man calls up the Mumbai police, and tells them he has placed five different \n\n\nbombs in the city -- all set to go off in some time. He wants four terrorists in \n\nexchange.  Does he get them? Who is behind it all? What's his motive? Is there \n\n\nmore than meets the eye?\n\n\n\n    Year OF RELEASE:2008                       IMDB RATING:8.2/10\n\n    Price=Rs 199";
                        strcpy(nom,"A WEDNESDAY                    ");
                        price=199;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 5:do {
                        cout<<"\n\n\t\t\t\t  RAAJNEETI\n\n\n\t\t\t178 min  -  Action | Crime | Drama \n\n\n\nJust about to acquire a PhD, a young man becomes embroiled in politics, deceit, \n\nlie and murder...\n\n\n\n    Year OF RELEASE:2010                       IMDB RATING:6.9/10\n\n    Price=Rs 299";
                        strcpy(nom,"RAAJNEETI                      ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 6:do {
                        cout<<"\n\n\t\t\t      CHAK DE INDIA!\n\n\n\t\t    153 min  -  Drama | Family | Sport\n\n\nThe story of a hockey player who returns to the game as a coach of a women's \n\nhockey team...\n\n\n    Year OF RELEASE:2007                       IMDB RATING:8.0/10 \n\n    Price=Rs 599";
                        strcpy(nom,"CHAK DE INDIA!                 ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 7:do {
                        cout<<"\n\n\t\t\t\t    AAMIR\n\n\n\t\t\t\tDrama | Thriller\n\n\n A doctor of Indian origin returning to Mumbai from London is forced to\n\n participate in a terrorist plot. \n\n\n    Year OF RELEASE:2008                       IMDB RATING:7.5/10\n\n    Price=Rs 199 ";
                        strcpy(nom,"AAMIR                          ");
                        price=199;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 8:do {
                        cout<<"\n\n\n\n\t\t\t\tBLACK FRIDAY \n\n\n\t\t     143 min  -  Crime | Drama | History \n\n\n\nBlack Friday is a film about the investigations following the 1993 serial Bombay\n\nbomb blasts,told through the different stories of the people involved --police,\n\n\nconspirators,victims, middlemen.\n\n\n\n    Year OF RELEASE:2004                      IMDB RATING:8.1/10\n\n    Price=Rs 299 ";
                        strcpy(nom,"BLACK FRIDAY                   ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 9:do {
                        cout<<"\n\n\n\n\t\t\t      RANG DE BASANTI \n\n\n\t\t    157 min  -  Action | Comedy | Drama \n\n\n\nA young women from England comes to India to make a documentary about her \n\n\ngrandfather's diary which was written in the 1920s about the Indian Independence \n\nwith five young men..\n\n\n\n    Year OF RELEASE:2006                       IMDB RATING:8.2/10\n\n    Price=Rs 299 ";
                        strcpy(nom,"RANG DE BASANTI                ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 10:do {
                        cout<<"\n\n\n\n\t\t\t  MUGHAL-E-AZAM (1960)\n\n\n\t\t 173 min  -  Drama | Musical | Romance \n\n\n\nSet in the 16th century AD, the movie brings to life the tale of the doomed \n\n\nlove affair between the Mughal Crown Prince Saleem and the beautiful, ill-fated \n\ncourt dancer, whose fervor and intensity perpetrates a war between the prince \n\n\nand his father the great Mughal Emperor Akbar, and threatensto bring an empire \n\n\nto its knees....\n\n\n\n    Year OF RELEASE:1960                       IMDB RATING:8.0/10\n\n    Price=Rs 399";
                        strcpy(nom,"MUGHAL-E-AZAM                  ");
                        price=399;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 11:do {
                        cout<<"\n\n\n\n\t\t\t\tMOTHER INDIA \n\n\n\t\t  172 min  -  Drama | Musical | Family \n\n\nIt is the tale that is constantly repeated in real life.Mother India is the \n\nevergreen story of a poor family's struggle to survive against the oppression of \nmoneylenders....  \n\n\n    Year OF RELEASE:1957                       IMDB RATING:7.5/10   \n\n    Price=Rs 299";
                        strcpy(nom,"MOTHER INDIA                   ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 12:do {
                        cout<<"\n\n\n\n\t\t\t\t  TERE BIN LADEN  \n\n\n\t\t\t\t95 min  -  Comedy  \n\n\n  Tere Bin Laden is a tongue-in-cheek comedy about an ambitious young news \n\n  reporter from Pakistan who is desperate to migrate to the US.When he comes \n\n  across an Osama bin Laden look alike,he hatches a scheme to produce a fake \n\n  Osama video and sell it to news channels as a breakthrough scoop!\n\n\n\n\n    Year OF RELEASE:2010                      IMDB RATING:7.4/10\n\n    Price=Rs 399";
                        strcpy(nom,"TERE BIN LADEN                 ");
                        price=399;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 13:do {
                        cout<<"\n\n\n\n\t\t\t      DIL CHAHTA HAI   \n\n\n\t\t\t183 min  -  Comedy | Drama \n\n\nThe film is about three distinct characters,their individual relationships and \n\nthe effect that these relationships have on them.     \n\n\n    Year OF RELEASE:2001                       IMDB RATING:8.2/10  \n\n    Price=Rs 199  ";
                        strcpy(nom,"DIL CHAHTA HAI                 ");
                        price=199;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 14:do {
                        cout<<"\n\n\n\n\t\t\t\tSALAAM BOMBAY! \n\n\n\t\t\t  113 min  -  Crime | Drama \n\n\nThe story of Krishna, Manju, Chillum and the other children on the streets of \n\nBombay. Sometimes they can get a temporary job sellng tea, but mostly they have \nto beg for money and keep out of the way of the police...\n\n\n    Year OF RELEASE:1988                       IMDB RATING:8.0/10 \n\n    Price=Rs 99";
                        strcpy(nom,"SALAAM BOMBAY!                 ");
                        price=99;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 15:do {
                        cout<<"\n\n\n\n\t\t\t\t  LAKSHYA    \n\n\n\t\t   186 min  -  War | Drama | Romance \n\n\n  A young,lazy, fickle minded man eventually joins the army to show that he too \n  is focused about the path he has to take in this lifetime. But will he be \n\n  resilient enough to carry out this task???\n\n\n    Year OF RELEASE:2004                       IMDB RATING:7.7/10\n\n    Price=Rs 199 ";
                        strcpy(nom,"LAKSHYA                        ");
                        price=199;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 16:do {
                        cout<<"\n\n\n\n\t\t\t\t   GURU \n\n\n\t\t166 min  -  Biography | Drama | Romance \n\n\n  A villager, Gurukant Desai, arrives in Bombay 1958, and rises from its streets \n\n  to become the GURU,the biggest tycoon in Indian history....\n\n\n    Year OF RELEASE:2007                       IMDB RATING:7.5/10  \n\n    Price=Rs 99  ";
                        strcpy(nom,"GURU                           ");
                        price=99;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 17:do {
                        cout<<"\n\n\n\n\t\t\t\t    BLACK     \n\n\n\t\t\t     122 min  -  Drama \n\n\nThe cathartic tale of a deaf, mute and blind girl, and her teacher who brings a \n\nray of light into her world of blackness...\n\n\n    Year OF RELEASE:2005                       IMDB RATING:8.0/10 \n\n    Price=Rs 299";
                        strcpy(nom,"BLACK                          ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 18:do {
                        cout<<"\n\n\n\n\t\t\t\t    SHOLAY  \n\n\n\t\t  188 min  -  Action | Adventure | Comedy \n\n\nAfter his family is murdered by a notorious and ruthless bandit, a former police \n\nofficer enlists the services of two outlaws to capture him... \n\n\n    Year OF RELEASE:1975                       IMDB RATING:7.9/10     \n\n    Price=Rs 599 ";
                        strcpy(nom,"SHOLAY                         ");
                        price=599;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 19:do {
                        cout<<"\n\n\n\n\t\t\t  SWADES:WE,THE PEOPLE   \n\n\n\t\t\t    210 min  -  Drama \n\n\nA successful Indian scientist returns to an Indian village to take his nanny to \n\nAmerica with him and in the process rediscovers his roots...   \n\n\n    Year OF RELEASE:2004                       IMDB RATING:8.3/10   \n\n    Price=Rs 299 ";
                        strcpy(nom,"SWADES                         ");
                        price=299;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    case 20:do {
                        cout<<"\n\n\n\n\t\t\t       ANDAAZ APNA APNA \n\n\n\t\t\t      160 min  -  Comedy \n\n\nTwo conmen competing for the hand of a heiress get drawn into love - and into \n\ntrying to save her from an evil criminal... \n\n\n    Year OF RELEASE:1994                       IMDB RATING:8.4/10 \n\n    Price=Rs 199  ";
                        strcpy(nom,"ANDAAZ APNA APNA               ");
                        price=199;
                        mani(nom,price);
                        cout<<"Do you want to continue with this movie???\n\n(Press Y for yes or any other character for no)\n\n";
                        cin>>ch1;
                    }while((ch1=='y')||(ch1=='Y'));
                    break;

                    default: cout<<"\n\nKindly select an option from the list....\n\n";
                }

                cout<<"\n\nDo you want to revisit the hindi collection???\n\n(Press Y for yes or any other character for no)\n\n\n";
                cin>>ch3;
                clrscr();
            }while((ch3=='Y')||(ch3=='y'));
        }
        else {
            cout<<"SORRY!!!We feature only two languages!!!please select one of them!!!";
        }
        cout<<"\n\nDo you want to buy any other DVD?\n\n(Press Y for yes or any other character for no)\n\n";
        cin>>c;
        clrscr();
    }while((c=='y')||(c=='Y'));

    c1.display();
    cout<<"\n\nNAME OF THE MOVIE             "<<"PRICE"<<"\t    "<<"NO. OF COPIES"<<"\t "<<"TOTAL COST"<<"\n\n\n";
    fout.seekg(0);

    while(!fout.eof()) {
        fout.getline(line,1000);
        cout<<line<<"\n";
       }

    cout<<"\n\nYour total bill is "<<::sum;

    if(flag==1) {
        do {
            cout<<"\n\nHow would you like to pay the bill???(press 1 or 2)";
            cout<<"\n\n1.Cash";
            cout<<"\n\n2.Credit Card\n\n";
            cin>>ch4;
            if(ch4==1) {
                cout<<"\n\nThe amount has been paid..\n\n";
                getch();
                break;
           }

            else if(ch4==2) {
                cout<<"\n\n"<<sum<<" has been deducted from your bank account..\n\n";
                getch();
               break;
           }

            else {
                cout<<"\n\nSorry...This kind of transaction is not allowed...\n\n\n";
                cout<<"Do you want to pay at all????\n\n(Press Y for yes or any other character for no)";
                cin>>ch5;
                clrscr();
            }

        }while((ch5=='Y')||(ch5=='y'));
        goto start;
    }

    else {
        cout<<"\n\n\nYou have not brought any movie....Do you want to buy one\n\n(Press Y for yes or any other character for no)????";
        cin>>ch6;
        clrscr();
        if((ch6=='n')||(ch6=='N')) {    
            cout<<"\n\n\nThank you for visiting!!!!!Come again soon!!!\n\n";
            goto start;
        }
        else
            goto label;
    }
}

else if(che==2) {     
    clrscr();
    cout<<"\n\n\n\n\n\t\t\t\tSHOP DETAILS\n\n\n";
	cout<<"\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
	cout<<"\t\t  #   TIMING: 11 AM TO 02 PM & 03 PM TO 05 PM                    \n";
    cout<<"\t\t  #   SHOP WILL CLOSED ON MONDAY.                                \n";
    cout<<"\t\t  #   GOODS ONCE SOLD WILL NOT BE EXCHANGED/REPLACED.            \n";
    cout<<"\t\t  #   VISA/MASTER CARD ACCEPTED.                                 \n";
    cout<<"\t\t  #   FOR ANY COMPLAINT CONTACT ONE OF THE CHAIR PERSON.         \n";
    cout<<"\t\t  #   AN ISO 9001-2000 CERTIFIED COMPANY.                        \n";
    cout<<"\t\t  #   WELL QUALIFIED STAFF MEMBERS.                              \n";
    cout<<"\t\t  #   WEBSITE :- www.moviemania.com                              \n";
    cout<<"\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
    getch();
    clrscr();
    goto start;
}

else if(che==3) {
    clrscr();
    search();
    getch();
    goto start;
}

else if(che==4) {
    clrscr();
    read();
    getch();
    goto start;
}

else if(che==5) {
    cout<<"\n\n\nThank you for visiting!!!!!Come again soon!!!\n\n\n\n\n";
    getch();
    exit(0);
}

else {
    cout<<"ERROR!!!!!PLS TYPE A VALID OPTION!!!!";
    getch();
    goto start;
}


fout.close();
getch();


}








