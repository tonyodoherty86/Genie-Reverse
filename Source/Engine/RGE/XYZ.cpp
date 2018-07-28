
//----- (0047E480) --------------------------------------------------------
void __thiscall XYZ::XYZ(XYZ *this)
{
  this->xValue = 0;
  this->yValue = 0;
  this->zValue = 0;
}

//----- (0047E490) --------------------------------------------------------
void __thiscall XYZ::XYZ(XYZ *this, int a, int b, int c)
{
  this->xValue = a;
  this->yValue = b;
  this->zValue = c;
}

//----- (0047E4B0) --------------------------------------------------------
BOOL __cdecl operator==(XYZ *one, XYZ *two)
{
  return one->xValue == two->xValue && one->yValue == two->yValue && one->zValue == two->zValue;
}

//----- (0047E4E0) --------------------------------------------------------
BOOL __cdecl operator!=(XYZ *one, XYZ *two)
{
  return one->xValue != two->xValue || one->yValue != two->yValue || one->zValue != two->zValue;
}

//----- (0047E530) --------------------------------------------------------
XYZ *__thiscall XYZ::operator+(XYZ *this, XYZ *result, XYZ *__$ReturnUdt)
{
  XYZ *v3; // eax@1
  XYZ newP; // [sp+4h] [bp-Ch]@1

  XYZ::XYZ(
    &newP,
    __$ReturnUdt->xValue + this->xValue,
    __$ReturnUdt->yValue + this->yValue,
    this->zValue + __$ReturnUdt->zValue);
  v3 = result;
  *result = newP;
  return v3;
}

//----- (0047E580) --------------------------------------------------------
XYZ *__thiscall XYZ::operator-(XYZ *this, XYZ *result, XYZ *__$ReturnUdt)
{
  XYZ *v3; // eax@1
  XYZ newP; // [sp+4h] [bp-Ch]@1

  XYZ::XYZ(
    &newP,
    this->xValue - __$ReturnUdt->xValue,
    this->yValue - __$ReturnUdt->yValue,
    this->zValue - __$ReturnUdt->zValue);
  v3 = result;
  *result = newP;
  return v3;
}

//----- (0047E5D0) --------------------------------------------------------
void __thiscall XYZ::rotateXYByFacet(XYZ *this, XYZ *refPoint, XYZ *rPoint, char facet)
{
  XYZ *v4; // esi@1
  double v5; // st7@2
  long double v6; // st5@2
  double v7; // st6@2
  long double v8; // st5@2
  long double v9; // st4@2
  XYZ *rPointa; // [sp+Ch] [bp+8h]@2

  v4 = rPoint;
  *rPoint = *this;
  if( facet )
  {
    v5 = (double)(this->xValue - refPoint->xValue);
    v6 = (double)(unsigned __int8)facet * 0.78539819;
    v7 = (double)(this->yValue - refPoint->yValue);
    *(float *)&rPointa = v6;
    v8 = sin(v6);
    v9 = cos(*(float *)&rPointa);
    v4->xValue = (signed __int64)(v9 * v5 - v8 * v7);
    v4->yValue = (signed __int64)(v9 * v7 + v8 * v5);
  }
}
