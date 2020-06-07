//----------------------------------------------------------------------------
#ifndef CustomersReportH
#define CustomersReportH
//----------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\QuickRpt.hpp>
#include <vcl\QRCtrls.hpp>
#include <Qrctrls.hpp>
#include <quickrpt.hpp>
//----------------------------------------------------------------------------
class TCustomerReport : public TQuickRep
{
__published:
    TQRLabel *QRLabel1;
private:
public:
   __fastcall TCustomerReport::TQuickReport1(TComponent* Owner);
};
//----------------------------------------------------------------------------
extern TCustomerReport *CustomerReport;
//----------------------------------------------------------------------------
#endif