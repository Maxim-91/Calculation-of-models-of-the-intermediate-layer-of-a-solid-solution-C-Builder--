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
 // �������� ����������� �����
 if (Edit1->Text==""||Edit2->Text==""||Edit3->Text==""||Edit4->Text==""||Edit5->Text==""||Edit6->Text==""||Edit7->Text==""||Edit8->Text=="")
 {
  ShowMessage("������ �� ��� ��� ����������!");
  goto z;
 }
{
 float // �� ���
 d1=StrToFloat(Edit1->Text),
 d2=StrToFloat(Edit2->Text),
 b1=StrToFloat(Edit3->Text),
 b2=StrToFloat(Edit4->Text),
 r1=StrToFloat(Edit5->Text),
 r2=StrToFloat(Edit6->Text),
 d12=StrToFloat(Edit7->Text),
 d22=StrToFloat(Edit8->Text),
 rc, bc, A1, A2, A3, d11, bf, bm, // ��� ��� ����������
 W1, W2, W3, W4, W5; // ��� ��� ��������
 rc=r1*r2*(d12+d22)/(r1*d22+r2*d12);
 bc=b1+b2+(b1*r1*d22+b2*r2*d12)/(r1*d22+r2*d12);
 d11=d1-d12;
 A1=(d1-d11)*rc*r2;
 A2=(d2-d22)*rc*r1;
 A3=(d12+d22)*r1*r2;
 // ���������� ����� ��� �������� ������� b
 W1=b1+bc+b2;
 W2=A1*(bc+b2);
 W3=A2*(bc+b1);
 W4=A3*(b1+b2);
 W5=A1+A2+A3;
 // ����������� �� ��������������� �������
 bf=W1-(W2+W3+W4)/W5;
 Edit9->Text=bf; // ���� �� �����

 // ����������� �� ������������� �������
 bm=b1+b2+(d1+d2)/(d1+d2)-(b1*r1*d2+r1*d2+b2*r2*d1+r2*d1)/(r1*d2+r2*d1);
 Edit10->Text=bm;  // ���� �� �����
 }
 z:
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
 // �������� ����������� �����
 if (Edit11->Text==""||Edit12->Text==""||Edit3->Text==""||Edit4->Text==""||Edit5->Text==""||Edit6->Text==""||Edit7->Text==""||Edit8->Text=="")
 {
  ShowMessage("������ �� ��� ��� ����������!");
  goto z;
 }
{
 float // �� ���
 b1=StrToFloat(Edit3->Text),
 b2=StrToFloat(Edit4->Text),
 r1=StrToFloat(Edit5->Text),
 r2=StrToFloat(Edit6->Text),
 d12=StrToFloat(Edit7->Text),
 d22=StrToFloat(Edit8->Text),
 D=StrToFloat(Edit11->Text),
 dD=StrToFloat(Edit12->Text),
 rc, bc, A3, A1, A2, d11, bf, bm, d1, d2, // ��� ��� ����������
 W1, W4, W2, W3, W5, // ��� ��� ��������
 n, i; // ���� ��� ������� �����

 n=D/dD; // ���������� ����� ���������
 // ������� ��������� �����
 d1=0-dD;
 d2=D+dD;

 // ������� ����� � �������
 StringGrid1->RowCount=n+2;
 StringGrid2->RowCount=n+2;

 // ������������ �������
 StringGrid1->Cells[0][0]="d1, ��";
 StringGrid1->Cells[1][0]="d2, ��";
 StringGrid1->Cells[2][0]="b";
 
 StringGrid2->Cells[0][0]="d1, ��";
 StringGrid2->Cells[1][0]="d2, ��";
 StringGrid2->Cells[2][0]="b";

 // ������� �������
 Series1->Clear();
 Series2->Clear();
 Series3->Clear();
 Series4->Clear();
 // ���� ��� ���������� n �����
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
  // ���������
  W1=b1+bc+b2;
  W2=A1*(bc+b2);
  W3=A2*(bc+b1);
  W4=A3*(b1+b2);
  W5=A1+A2+A3;
  // ����������� �� ��������������� �������
  bf=W1-(W2+W3+W4)/W5;

  // ����������� �� ������������� �������
  bm=b1+b2+(d1+d2)/(d1+d2)-(b1*r1*d2+r1*d2+b2*r2*d1+r2*d1)/(r1*d2+r2*d1);

  // �������� ���������� � ������� 1
  StringGrid1->Cells[0][i]=d1;
  StringGrid1->Cells[1][i]=d2;
  StringGrid1->Cells[2][i]=bf;

  // �������� ����� � ������ 1
  Series1->AddXY(d1,bf,"",clRed);
  Series2->AddXY(d2,bf,"",clBlue);

  // �������� ���������� � ������� 2
  StringGrid2->Cells[0][i]=d1;
  StringGrid2->Cells[1][i]=d2;
  StringGrid2->Cells[2][i]=bm;

  // �������� ����� � ������ 2
  Series3->AddXY(d1,bm,"",clRed);
  Series4->AddXY(d2,bm,"",clBlue);
 }
 }
 z:
}
//---------------------------------------------------------------------------





void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
 Form1->Close(); // ������� ���� ��������         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
 // �������� �������� �����, ����� �� ����� � ���� ���������� �����������
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit5KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit8KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit11KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit12KeyPress(TObject *Sender, char &Key)
{
{if ((Key >= '0') && (Key <= '9') || Key == VK_BACK || Key =='-') {}  // ����� � 'Key == '-'' - �� ������ ������ ��� ������������� �����, �� ���������� ����� ������.
  else if (Key == ',') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else if (Key == '.') // �������
        {
        if (((TEdit*)Sender)->Text.Pos(DecimalSeparator)!=0) // ���� ������� ��� ����
                Key = 0;
        else // ���� ��� ��� �������
                Key = DecimalSeparator;
        }

  else Key = 0; // �� �����
  if (Key==0) ShowMessage("�� ����� �� ����� ������! ����� ������� ���� ����� �� 0 �� 9, ������ ' , ' (���� �� ������� ������) �� ' - ' (���� ��'����)"); }         
}
//---------------------------------------------------------------------------

