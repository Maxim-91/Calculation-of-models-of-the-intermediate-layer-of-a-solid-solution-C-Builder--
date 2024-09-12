//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
 // перевірка заповненості даних
 if (Edit1->Text==""||Edit2->Text==""||Edit3->Text==""||Edit4->Text==""||Edit5->Text==""||Edit6->Text==""||Edit7->Text==""||Edit8->Text=="")
 {
  ShowMessage("Введіть всі дані для розрахунків!");
  goto z;
 }
{
 float // вх дані
 d1=StrToFloat(Edit1->Text),
 d2=StrToFloat(Edit2->Text),
 b1=StrToFloat(Edit3->Text),
 b2=StrToFloat(Edit4->Text),
 r1=StrToFloat(Edit5->Text),
 r2=StrToFloat(Edit6->Text),
 d12=StrToFloat(Edit7->Text),
 d22=StrToFloat(Edit8->Text),
 rc, bc, A1, A2, A3, d11, bf, bm, // дані для розрахунків
 W1, W2, W3, W4, W5; // дані для спрощень
 rc=r1*r2*(d12+d22)/(r1*d22+r2*d12);
 bc=b1+b2+(b1*r1*d22+b2*r2*d12)/(r1*d22+r2*d12);
 d11=d1-d12;
 A1=(d1-d11)*rc*r2;
 A2=(d2-d22)*rc*r1;
 A3=(d12+d22)*r1*r2;
 // обчислення даних для спрощень формули b
 W1=b1+bc+b2;
 W2=A1*(bc+b2);
 W3=A2*(bc+b1);
 W4=A3*(b1+b2);
 W5=A1+A2+A3;
 // розрахукнок за феноменологічною моделлю
 bf=W1-(W2+W3+W4)/W5;
 Edit9->Text=bf; // вивід на екран

 // розрахукнок за макроскопічною моделлю
 bm=b1+b2+(d1+d2)/(d1+d2)-(b1*r1*d2+r1*d2+b2*r2*d1+r2*d1)/(r1*d2+r2*d1);
 Edit10->Text=bm;  // вивід на екран
 }
 z:
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
 // перевірка заповненості даних
 if (Edit11->Text==""||Edit12->Text==""||Edit3->Text==""||Edit4->Text==""||Edit5->Text==""||Edit6->Text==""||Edit7->Text==""||Edit8->Text=="")
 {
  ShowMessage("Введіть всі дані для розрахунків!");
  goto z;
 }
{
 float // вх дані
 b1=StrToFloat(Edit3->Text),
 b2=StrToFloat(Edit4->Text),
 r1=StrToFloat(Edit5->Text),
 r2=StrToFloat(Edit6->Text),
 d12=StrToFloat(Edit7->Text),
 d22=StrToFloat(Edit8->Text),
 D=StrToFloat(Edit11->Text),
 dD=StrToFloat(Edit12->Text),
 rc, bc, A3, A1, A2, d11, bf, bm, d1, d2, // дані для розрахунків
 W1, W4, W2, W3, W5, // дані для спрощень
 n, i; // змінні для ведення відліків

 n=D/dD; // визначення кроків обчислень
 // задання нульового кроку
 d1=0-dD;
 d2=D+dD;

 // задання строк в таблиці
 StringGrid1->RowCount=n+2;
 StringGrid2->RowCount=n+2;

 // найменування таблиці
 StringGrid1->Cells[0][0]="d1, нм";
 StringGrid1->Cells[1][0]="d2, нм";
 StringGrid1->Cells[2][0]="b";
 
 StringGrid2->Cells[0][0]="d1, нм";
 StringGrid2->Cells[1][0]="d2, нм";
 StringGrid2->Cells[2][0]="b";

 // очистка графіків
 Series1->Clear();
 Series2->Clear();
 Series3->Clear();
 Series4->Clear();
 // цикл для розрахунків n кроків
 for (i=1; i<=n+1; i++)
 {
  d1=d1+dD;
  d2=d2-dD;
  rc=r1*r2*(d12+d22)/(r1*d22+r2*d12);
  bc=b1+b2+(b1*r1*d22+b2*r2*d12)/(r1*d22+r2*d12);
  d11=d1-d12;
  A1=(d1-d11)*rc*r2;
  A2=(d2-d22)*rc*r1;
  A3=(d12+d22)*r1*r2;
  // спрощення
  W1=b1+bc+b2;
  W2=A1*(bc+b2);
  W3=A2*(bc+b1);
  W4=A3*(b1+b2);
  W5=A1+A2+A3;
  // розрахукнок за феноменологічною моделлю
  bf=W1-(W2+W3+W4)/W5;

  // розрахукнок за макроскопічною моделлю
  bm=b1+b2+(d1+d2)/(d1+d2)-(b1*r1*d2+r1*d2+b2*r2*d1+r2*d1)/(r1*d2+r2*d1);

  // введення результату в таблицю 1
  StringGrid1->Cells[0][i]=d1;
  StringGrid1->Cells[1][i]=d2;
  StringGrid1->Cells[2][i]=bf;

  // внесення даних в графік 1
  Series1->AddXY(d1,bf,"",clRed);
  Series2->AddXY(d2,bf,"",clBlue);

  // введення результату в таблицю 2
  StringGrid2->Cells[0][i]=d1;
  StringGrid2->Cells[1][i]=d2;
  StringGrid2->Cells[2][i]=bm;

  // внесення даних в графік 2
  Series3->AddXY(d1,bm,"",clRed);
  Series4->AddXY(d2,bm,"",clBlue);
 }
 }
 z:
}
//---------------------------------------------------------------------------





void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
 Form1->Close(); // закрити вікно програми         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
 // перевірка введених даних, число чи літера і вивід відповідного повідомлення
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit5KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit8KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit11KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit12KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // цифры и 'Key == '-'' - на всякий случай для отрицательных чисел, по надобности можно убрать.
  else if (Key == ',') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else if (Key == '.') // запятая
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // если запятая уже есть
                Key = 0;
        else // если еще нет запятой
                Key = DecimalSeparator;
        }

  else Key = 0; // не цифра
  if (Key==0) ShowMessage("Ви ввели не вірний символ! Можна вводити лише цифри від 0 до 9, символ ' , ' (якщо це дробове чисело) та ' - ' (якщо від'ємне)"); }         
}
//---------------------------------------------------------------------------

