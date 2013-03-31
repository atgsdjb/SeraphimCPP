namespace Seraphim
{
    enum month
    {
      January = 1,
      February, March, April, May, June, July, August, September, october, November,December
    };
  class Date
  {
   private:
   int y;
   month m;
   int d;
   bool isIntercalary();
   public:
    Date(int yy,month mm,int dd);
    int getDay(){return d;};
    int getYer(){return y;};
    month getMonth(){return m;};
  };


};
