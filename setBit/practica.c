
extern void myputchar(char x);
extern char getch(); 
extern void WriteBit(char *dato, char pos, char val);
void myItoa(unsigned int num,int base, char *salida);
void puts(char *str);
char symbol[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int j,i;


int main()
{     
    char datos=0;
    while(1)
    { 
        WriteBit(&datos,2,1);
        myputchar(datos);
    }
        return 0;  
}

void myItoa(unsigned int num,int base, char *salida)
{
    char aux_string[16];
    i=0,j=0;

    if(num!=0){
     while(num){ 
            *(aux_string+i)=symbol[num%base];
            num=num/base;
            i++;
    }
        *(aux_string+i)=0;
        

        while(i)
        {
            i--;
           (*(salida+j))=aux_string[i];
           j++;

        }
        (*(salida+j))=0;
    }
    else 
    {
        
        salida[0]='0';
        salida[1]=0;
    
    }
}

void puts(char* str)
{
    while(*str)
    {
        myputchar(*str++);
    }
}


