#include <iostream>
#include<fstream>
//#include<string>
using namespace std;
void GameInit();
void LoadMap();
void LoadCharacter();
string MakeUpper(string s);
fstream  EarthMap,Characters;

int main()
{
    GameInit();
    string AdmCtrl;
    cin>>AdmCtrl;
    AdmCtrl=MakeUpper(AdmCtrl);
    while(AdmCtrl.compare("EXIT")!=0)//||AdmCtrl.compare("exit")!=0)
    {

        if(AdmCtrl.compare("CHARACTER")==0)
        LoadCharacter();
        if(AdmCtrl.compare("MAP")==0)
        LoadMap();
        cin>>AdmCtrl;
        AdmCtrl=MakeUpper(AdmCtrl);

    }
    return 0;
}

void GameInit()
{
     //LoadMap();

}
void LoadMap()
{
    string  Map_Code;
    EarthMap.open("./map.c");
    if(!EarthMap)cout<<"加载地图资源失败..."<<endl;
    else
    {
        cout<<"加载地图资源成功..."<<endl;
        while ( getline(EarthMap, Map_Code) )
        {
                if(Map_Code.compare("[map]")==0)
                {cout << Map_Code<< endl;
                continue;}
                cout << Map_Code<< endl;
        }
    }

    EarthMap.close();
//    {
//        cout<<"加载地图资源成功..."<<endl;
//        while(!EarthMap.eof())
//        {
//            EarthMap>>MapCode;
//            if(isdigit(MapCode))
//                {
//                    //EarthMap.seekg(-1,ios::cur);
//                    cout<<MapCode<<endl;
//                }
//            else
//                cout<<MapCode;
//        }
}

void LoadCharacter()
{
    string  Chac_Code;
    Characters.open("./Characters.c");
    if(!Characters)cout<<"加载人物资源失败..."<<endl;
    else
    {
        cout<<"加载人物资源成功..."<<endl;
        while ( getline(Characters, Chac_Code) )
        {
                if(Chac_Code.compare("[Characters]")==0)
                {cout << Chac_Code<< endl;
                continue;}
                cout << Chac_Code<< endl;
        }
    }

    Characters.close();
}

string MakeUpper(string s)
{
        for (int n = 0; n<20 ; n++)
    {
        s[n] = toupper(s[n]);
    }
    return s;
}

