#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

struct rectangle //Структура прямоугольник
{
    unsigned a;//длина
    unsigned b;//ширина
    unsigned p;//периметр
    unsigned s;//площадь
};
struct dot//Структура точка
{
    float x;
    float y;
};
struct line//Структура отрезок
{
    float dl;
    struct dot a;
    struct dot b;
};

void un_input_int(unsigned *input) //Проверка на целое положительное число
{
    float pr;
    do {
        printf("Целое положительное число: ");
        scanf("%f", &pr);
        *input=pr;
       }   while ((*input-pr)!=0||(pr<0)||pr>4294967295);
}
char* Preob(unsigned ch)//Преобразовние в двоичную систему
{
    int i=0, len=0;
    char boof[33];
    char* boof1=malloc(sizeof(char)*33);
    for(i=0;i<33;i++)
    {
        (ch%2==0)?((boof[i]='0')):((boof[i]='1'));
        ch=ch/2;
        len++;
        if(ch==0)
        {
            boof[i+2]='\0';
            break;
        }
    }
    for(i=0;i<=len;i++)
    {
        boof1[i]=boof[len-1-i];

    }
    boof1[len]='\0';
    return boof1;
}
void Op (struct rectangle* input)//Вычисление периметра и площади
{
    input->p=(2*(input->a))+(2*(input->b));
    input->s=input->a*input->b;
}
struct line dlina(struct dot a,struct dot b)//Вычисление длины отрезка
{
    struct line otr;
    otr.dl=sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2));
    return otr;
}
void input_dot(struct dot* a)//Ввод координат точек
{
    printf("Введите X: ");
    scanf("%f",&a->x);
    printf("Введите Y: ");
    scanf("%f",&a->y);
}

void first()//Первое задание
{
    unsigned ch;
    un_input_int(&ch);
    printf("%s\n",Preob(ch));
}
void second()//Второе задание
{
    struct rectangle in;
    printf("Введите длину: ");
    un_input_int(&in.a);
    printf("Введите ширину: ");
    un_input_int(&in.b);
    Op(&in);
    printf("Периметр равен = %u\n",in.p);
    printf("Площадь равна = %u\n",in.s);
}
void third()//Третье задание
{
    struct line otr;
    struct dot a, b;
    printf("Введите координаты точки а\n");
    input_dot(&a);
    printf("Введите координаты точки b\n");
    input_dot(&b);
    otr=dlina(a,b);
    printf("Длина отрезка равна: %f\n",otr.dl);
}
int* init_mas(int* mas, unsigned n, unsigned m)//Инициализация массива
{
    return (int*)calloc(n*m,sizeof(int));
}
void vvod_mas(int* mas, unsigned n, unsigned m)//Ввод эл-ов массива
{
    for (unsigned i = 0; i<n; i++)  // цикл по строкам
      {
        for (unsigned j = 0; j<m; j++)  // цикл по столбцам
        {
          printf("mas[%d][%d] = ", i, j);
          scanf("%d", (mas + i*m + j));
        }
      }
}
void out_mas(int* mas, unsigned n, unsigned m)//Вывод массива
{
    for (int i = 0; i<n; i++)  // цикл по строкам
      {
        for (int j = 0; j<m; j++)  // цикл по столбцам
        {
          printf("%2d ", *(mas + i*m + j));
          //printf("%2d ", mas[i][j]);
        }
        printf("\n");
      }
}
void four()
{
    unsigned n, m;
    int* mas;
    printf("Введите кол-во строк n\n");
    un_input_int(&n);
    printf("Введите кол-во столбцов m\n");
    un_input_int(&m);
    mas=init_mas(mas,n,m);
    vvod_mas(mas,n,m);
    out_mas(mas,n,m);
}
int main()
{

    //first();
    //second();
    //third();
    four();
    return 0;
}
