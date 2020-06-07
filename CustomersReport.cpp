//----------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "CustomersReport.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
TCustomerReport *CustomerReport;
//----------------------------------------------------------------------------
__fastcall TCustomerReport::TCustomerReport(TComponent* Owner)
    : TQuickRep(Owner)
{
}
//----------------------------------------------------------------------------