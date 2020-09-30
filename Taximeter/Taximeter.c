#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define screen_refresh 0.2
#define km 1000
#define pulse_mt 2.5
#define tarifa_km 10
#define tiempo_espera 60
#define time_pulse_flag 0.050

typedef struct taxi_record
{
    unsigned int cuenta;
    unsigned int pulsos_total;
    unsigned int pulsos_cobro;
    unsigned char status_pasajero;
    unsigned char flag_pulso;
    unsigned char inicio_viaje;
    unsigned char flag_pulso_time;
}taxi_record;

void taxi_status(taxi_record *taxi,clock_t *time1,clock_t *time2);

int main()
{
    taxi_record taxi={0,0,0,0,0,0,0};
    clock_t time1,time2,time_pulse_1,time_pulse_2,timer_pulse_flag_1,timer_pulse_flag_2;
    time1=clock();
    time_pulse_1=clock();
    timer_pulse_flag_1=clock();
    while(1)
    {
        if(kbhit())
            {
                switch(getch())
                {

                case 'm':
                    taxi.status_pasajero+=1;
                    taxi.status_pasajero=(taxi.status_pasajero)*(taxi.status_pasajero<3);
                    break;

                case 'p':
                    taxi.pulsos_total+=1;
                    taxi.pulsos_cobro+=(taxi.status_pasajero==1);
                    taxi.flag_pulso==0;
                    taxi.flag_pulso_time=1;
                    break;

                }
            }
        time2=clock();
        time_pulse_2=clock();
        timer_pulse_flag_2=clock();
        if(((time2-time1)/CLOCKS_PER_SEC)>screen_refresh)
        {
            taxi_status(&taxi,&time1,&time2);
        }
//--------------------------------------------------------------------------------------------------------------------//
        if((((time_pulse_2-time_pulse_1)/CLOCKS_PER_SEC)>tiempo_espera) && (taxi.inicio_viaje==1) && taxi.flag_pulso==1 )
        {
            time_pulse_1=time_pulse_2;
            taxi.pulsos_cobro+=5;
            taxi.pulsos_total+=5;
        }

        else if((((time_pulse_2-time_pulse_1)/CLOCKS_PER_SEC)>tiempo_espera))
        {
            time_pulse_1=time_pulse_2;
        }

        if(taxi.flag_pulso_time==1 && ((timer_pulse_flag_2-timer_pulse_flag_1)/CLOCKS_PER_SEC)>time_pulse_flag)
        {
            taxi.flag_pulso_time==0;
            timer_pulse_flag_1=timer_pulse_flag_2;
        }
//-------------------------------------------------------------------------------------------------------------------//
    }

    return 0;
}

void taxi_status(taxi_record *taxi,clock_t *time1,clock_t *time2)
{
    static int aux_cuenta=0;
    /*--------------------------------*/
    *time1=*time2;
    system("cls");
    if(taxi->status_pasajero==0)
    {
        printf("LIBRE ");
        printf("FLAG OCUPADO=0\n");
        taxi->cuenta=0;
        taxi->inicio_viaje=0;
    }
    else if(taxi->status_pasajero==1)
    {
        taxi->cuenta+=((10)*(taxi->cuenta==0));
        aux_cuenta=(int)((taxi->pulsos_cobro*pulse_mt)/km)*tarifa_km;
        taxi->flag_pulso==0;
        printf("ACTUAL=%d ",taxi->cuenta+aux_cuenta);
        printf("FLAG OCUPADO=1\n");
        printf("pulsos=%d",taxi->pulsos_cobro);
    }
    else
    {
        printf("PAGAR=$%d",taxi->cuenta+aux_cuenta);
        printf("FLAG OCUPADO=1\n");
    }

}


