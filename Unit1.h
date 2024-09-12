//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
#include <Chart.hpp>
#include <Grids.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label2;
        TEdit *Edit3;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit4;
        TLabel *Label5;
        TEdit *Edit5;
        TEdit *Edit6;
        TLabel *Label6;
        TGroupBox *GroupBox2;
        TLabel *Label7;
        TEdit *Edit7;
        TLabel *Label8;
        TEdit *Edit8;
        TImage *Image1;
        TBitBtn *BitBtn1;
        TEdit *Edit9;
        TLabel *Label9;
        TEdit *Edit10;
        TLabel *Label10;
        TLabel *Label11;
        TEdit *Edit11;
        TEdit *Edit12;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TChart *Chart1;
        TChart *Chart2;
        TStringGrid *StringGrid2;
        TStringGrid *StringGrid1;
        TBitBtn *BitBtn2;
        TFastLineSeries *Series1;
        TFastLineSeries *Series2;
        TFastLineSeries *Series3;
        TFastLineSeries *Series4;
        TBitBtn *BitBtn3;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit6KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit7KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit8KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit11KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit12KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 