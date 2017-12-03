#include <iostream>

using namespace std;
int permuation_box[48] = {32,1,2,3,4,5,
                          4,5,6,7,8,9,
                        8,9,10,11,12,13,
                        12,13,14,15,16,17,
                        16,17,18,19,20,21,
                        20,21,22,23,24,25,
                        24,25,26,27,28,29,
                        28,29,30,31,32,1} ;

int st_box[32] = {16,7,20,21,29,12,28,17,
                  1,15,23,26,5,18,31,10,
                  2,8,24,14,32,27,3,9,
                  19,13,30,6,22,11,4,25} ;
char mask(unsigned long long num , char i ) // input return crossponding input //
{

return (num&(1<<i))>>i ;
}
#define MASK(data,i)    mask(data,i)

#define SET_BIT(p,n) ((p) |= (1 << (n)))

 unsigned  long long     MaskRange(unsigned long long  data , int   start  , int  finsh  )
{     long long  i = 0 ;unsigned  long long  mask1 = 0  ;
   for (i = start ; i <= finsh ; i++ )
   {
      SET_BIT(mask1,i);
   }

   return  ( data&mask1) >> start ;
}
long long pbox(unsigned long long input)

{
   unsigned  long long  result = 0 ;
    for(int i = 0 ;i < 48 ; i++)
	{

		 result |= MASK(input,32-permuation_box[i]);
		 if (i != 47)
         {
             result = result<<1;
         }

	}
    return result ;
}

// s box //

int s[8][4][16] = {
              {  {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
                {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
                {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13},
                {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0}
              } ,

              {
                  {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
                 {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
                 {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
                 {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
                 } ,

                 {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8  },
                  {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1  },
                  {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7  },
                  {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12 }
                  },

                  {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15 },
                   {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9  },
                   {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4  },
                   {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14 }
                   },

                   	{{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9  },
                    {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6  },
                    {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14 },
                    {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3  }},

                        {{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11 },
                    {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8  },
                    {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6  },
                    {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13 }},

                        {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1  },
                    {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6  },
                    {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2  },
                    {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12 }},

                        {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7  },
                    {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2  },
                    {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8  },
                    {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11 }}
                    };


unsigned long long sbox (unsigned long long input )
{

unsigned long long result = 0 ;
 unsigned long long sm[8] = {0xfc0000000000 ,0x03f000000000 ,0x000fc0000000 ,0x00003f000000 , 0x000000Fc0000 , 0x00000003F000 , 0x000000000Fc0 , 0x00000000003f} ;
  for(int i =0 , j = 7  ; i <8  ; i++ )
  {

  int temp = ( (sm[i] & input)>> j*6 ) ;
  int mid = 0  ; int side = 0 ;
mid = MaskRange(temp , 1, 4) ;
side = mask(temp ,0)|( mask(temp,5)<<1) ;

     result |= s[i][side][mid] ;

  if (i!=7)
  {
      result = result << 4 ;
  }
      j--;


  }



return result ;
}



long long striaghtbox(long long input )
{
unsigned  long long  result = 0 ;
    for(int i = 0 ;i < 32 ; i++)
	{

		 result |= MASK(input,32-st_box[i]);
		 if (i != 31)
         {
             result = result<<1;
         }

	}
    return result ;



}


















int main()
{
    long long plain, key  ;

   cin>>hex>>plain;
     cin >> hex >> key ;

    long long temp  = pbox(plain)^key ;
//cout<<hex <<temp <<endl;
//long long ehab = 0x57FB0266F918 ;
  long long temp2 = sbox(temp) ;



    cout <<hex <<uppercase <<striaghtbox(temp2) ;




}
