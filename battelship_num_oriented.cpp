#include <iostream>
#include <string.h>
#include <math.h>
#include <cstdlib>
using namespace std;
//------------------------------------------------------------------------------------------------------------------------------
struct table{
// tabella
    int gridprime[5][5]={
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
    };
};
//-------------------------------------------------------------------------------------------------------------------------------
void printtable(table* grid){
    for (int i=0; i<5; i++){
        for (int c=0; c<5; c++){
            cout<< (*grid).gridprime[i][c]<<" ";
        }
        cout<<"\n";
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
bool gridcheck(int object){
// controlla se nella griglia di 0 c'è un uno o un miss
    if (object == 1){
        //cout<< object;
        return true;
    }else{
       //cout << object;
        return false;
    }
}
//----------------------------------------------------------------------------------------------------------------------------
void gridshipadder(table* grid){
// aggiunge le navi nella posizione scelta
    int i;
    do{
        cout<< "==================================\n";
        cout<< "inserisci due coordinate da 1 a 5\n"; 
        cout<< "==================================\n";
        int xas;
        int yas;
        bool flagcontrolx=true; 
        bool flagcontroly= true;
        do{
            cin>>xas;
           // cout<< "debug1\n";
            if (xas<=5 && xas>0){
              //  cout << "debug7lucky\n"; // fa le bizze se prende una lettera in imput per sbaglio
                flagcontrolx=false;         // e se prendiamo un numero invalido prima di uno valido prende solo il valido e fa casino
            }
        }
        while(flagcontrolx==true);
        //flagcontrolx=true;
        //cout<< "\n";
         do{
            //cout<< "debug3\n";
            cin>>yas;
            //cout<< "debug2\n";
            if (yas<=5 && yas>0){
                flagcontroly=false;
            }
        }
        while(flagcontroly==true);
        //flagcontroly=true;       
       // cout<< "\n";
        if ((*grid).gridprime[xas-1][yas-1]==0){
        (*grid).gridprime[xas-1][yas-1]=1;
        cout<< "==================================\n";
        cout<< "aggiornamento di posizione\n";
        cout<< "==================================\n";
        printtable(grid);
        //cout<< "\n",
        i++;
        }
    }
    while (i<4);
}
//---------------------------------------------------------------------------------------------------------------------------
void stagecheck(table* gridup, table* gridown){
    cout<< "--------------\n";
    cout<< "radar opponent\n";
    cout<< "--------------\n";
    printtable(gridup);
    cout<<"-o-o-o-o-\n";
    cout<< "----------------\n";
    cout<< "posizione player\n";
    cout<< "----------------\n";
    printtable(gridown);
}
//-------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------
void hitormiss(bool ship){
// controlla se c'e una hit or miss nella griglia e restituisce un hit or miss
    if (ship== true){
        cout<< "==================================\n";
        cout<<"hit\n";
        cout<< "==================================\n";
    }else{   
        cout<< "==================================\n";
        cout<< "miss\n";
        cout<< "==================================\n";
}
}
//----------------------------------------------------------------------------------------------------------------------------------
bool instancecheckrepeatCpu(int x, int y, table* grid){
    // controlla se le cordinate della cpu sono gia state prese e ripete se accaduto
    if ((*grid).gridprime[x][y]==2 ||(*grid).gridprime[x][y]==3){
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void opponentbuilder(table* grioppo){
    srand(time(NULL));
    int incrementale=0;
    int randomx;
    int randomy;
    //cout << incrementale<< "debug a sorpresa\n";
    do{
        //cout << incrementale<< "debug assortito\n";
         randomx = rand()%5;
         randomy = rand()%5;
        //cout<< randomx << "\n" << randomy << "\n"; // debug
        if (gridcheck((*grioppo).gridprime[randomx][randomy])==false){ 
            (*grioppo).gridprime[randomx][randomy]= 1;
            incrementale++;
            //cout<< incrementale << "qui\n";
        }else{
            cout<< "debug error warnig\n";
        }
    }
    while(incrementale<4); 


}
//--------------------------------------------------------------------------------------------------------------------------------------
void gridupdate(bool bo, table* grid, int x, int y){
    if (bo== true){
        (*grid).gridprime[x][y]=2;
    }else{
        if ((*grid).gridprime[x][y]==3 || (*grid).gridprime[x][y]==2){
            cout<< "==================================\n";
            cout<< "Error position already filled,\n";
            cout<<"skipping turn\n";  // si ripete due volte ma non ho la voglia di correggerlo
            cout<< "==================================\n";
        }else{
            (*grid).gridprime[x][y]=3;
        }
}
}
//----------------------------------------------------------------------------------------------------------------------------------
void battlesimulatiom(table* upper, table* player, table* opponent, table* upperopponent){
// fa partire il loop della battaglia
int playerscore=0;
int opponentscore=0; 
bool flagcontrolx=true; 
bool flagcontroly= true;
int randomx, randomy;
int turncounter=1;                                                                         
do{
    cout<< "==================================\n";
    cout<<"{Global Turn: "<< turncounter<< " }\n";
    turncounter++;
    int xas= 0;
    int yas= 0;  
   cout<< "==================================\n";
   cout<< "Player turn\n"; 
   cout<< "==================================\n";
   cout<< "istruzioni: 1 = nave, 2 = colpito,\n";
   cout<< "3 = Mancato, 0 = casella vuota\n";
   cout<< "==================================\n";
           do{
            cin>>xas;
            //cout<<xas<< "debug1\n";
            if (xas<=5 && xas>0){
              //  cout << "debug7lucky\n"; 
                flagcontrolx=false;
                xas = xas-1;
            }
        }
        while(flagcontrolx==true);   //questa sezione ha dei problemi purtroppo vedi shipadder
        //flagcontrolx=true;
        //cout<< "\n";
         do{
            //cout<< "debug3\n";   
            cin>>yas;
            //cout<< yas<<"debug2\n";
            if (yas<=5 && yas>0){
                flagcontroly=false;
                yas= yas-1;
            }
        }
        while(flagcontroly==true);
        //flagcontroly=true;       
        //cout<< "\n";
        if(gridcheck((*opponent).gridprime[(xas)][(yas)])== true){
            playerscore++;
        }
        hitormiss((*opponent).gridprime[(xas)][(yas)]);
        gridupdate(gridcheck((*opponent).gridprime[xas][yas]),upper,xas,yas);
        //stagecheck(upper, player);
        gridupdate(gridcheck((*opponent).gridprime[xas][yas]),opponent,xas,yas);
        bool flag =false;
        cout<< "==================================\n";
        cout<< "opponent turn\n";
        cout<< "==================================\n";
        do{
        randomx = rand()%5;
        randomy = rand()%5;  
        flag=instancecheckrepeatCpu(randomx, randomy,player);
        }
        while (flag== false);
         if(gridcheck((*player).gridprime[randomx][randomy])== true){
            opponentscore++;
        }
        hitormiss((*player).gridprime[randomx][randomy]);
        gridupdate(gridcheck((*player).gridprime[randomx][randomy]),player,randomx,randomy);
        gridupdate(gridcheck((*player).gridprime[randomx][randomy]),upperopponent,randomx,randomy);
        stagecheck(upper, player);
}
while(opponentscore<4 && playerscore<4);
if (playerscore== 4){
    cout<< "player wins";
}else{
    cout<< "cpu wins";
}

}
//------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    cout<< "==================================\n";    //non eliminabile altrimenti crepa tutto per nessuna ragine
   cout<< "istruzioni: 1 = nave, 2 = colpito,\n";
   cout<< "3 = Mancato, 0 = casella vuota\n";
    cout<< "==================================\n";
    table gridplayer;
    table gridCpu;
    table Gridopponent;
    table Gridopponent_Upper;
    stagecheck(&Gridopponent, &gridplayer);
    gridshipadder(&gridplayer);
    opponentbuilder(&gridCpu);
    stagecheck(&Gridopponent, &gridplayer);
    battlesimulatiom(&Gridopponent, &gridplayer, &gridCpu, &Gridopponent_Upper);
    return 0;
}