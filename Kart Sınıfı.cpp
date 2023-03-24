#include<iostream>
#include<time.h>



#define kupa (0)
#define sinek (1)
#define maca (2)
#define karo (3)

#define as (0)
#define vale (10)
#define kiz (11)
#define kral (12)

// Neler Gerekli?


using namespace std;

class Kart
{
  
  private:
  int seri;
  int deger;

  public:
      Kart ( int seri = kupa , int deger = 2 )

      {

          this->seri = seri;
          this->deger = deger;

      }

      int getSeri()const
          
        {
    
             return seri;
    
        }

        int getDeger()const
          
        {
    
             return deger;
    
        }

        void yazdir()const

        {

            switch(seri)

            {

                case kupa:
                cout<<"Kupa ";
                break;

                case sinek:
                cout<<"Sinek ";
                break;

                case maca:
                cout<<"Maca ";
                break;

                case karo:
                cout<<"Karo ";
                break;

            }
            
            cout<<" ";
            switch(deger)

            {

                case as:
                cout<<"As";
                break;

                case vale:
                cout<<"Vale";
                break;

                case kiz:
                cout<<"Kiz";
                break;

                case kral:
                cout<<"Kral";
                break;

                default:
                cout<<deger +1;
                break;

            }

            cout<<" ";
        }


};

class Deste
{

    Kart kartlar[52];
    int top;
    public:
        Deste()

        {
            top = 0;
            int i;
            for(i=0;i<52;i++)

            {

                kartlar[i]=Kart(i/13,i%13); // 0-12 kupa, 13-25 sinek, 26-38 maca, 39-51 karo

            }
        }


        void yazdir()

        {

            int i;
            for(i=0;i<52;i++)

            {

                kartlar[i].yazdir();
                cout<<endl;

            }

        }
     

     void karistir( int kackere = 50)

     {

        Kart temp;

        int i;
        for ( i = 0; i < kackere; i++)

        {

            int rastgele1 = rand() % 52;
            int rastgele2 = rand() % 52;

            temp = kartlar[rastgele1];
            kartlar[rastgele1] = kartlar[rastgele2];
            kartlar[rastgele2] = temp;
            
        }
     }

      Kart getir()

      {

        return kartlar[top++]; // top++ ile topu bir arttiriyoruz ve kartlar[top] degerini donduruyoruz 

      }

};


int main()

{
    
    system("color B");
    srand(time(NULL));
    Deste deste;
    deste.yazdir();
    deste.karistir(500);
    cout<<endl<<endl;
    deste.yazdir();
    cout<<endl<<endl;
    deste.getir().yazdir();
    deste.getir().yazdir();
    




    return 0;

}
