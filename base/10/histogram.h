namespace Seraphim{
	class Histogram{
		private: float *section;
			 int countSection;
			 float min;
			 float max;
		public:
			 Histogram(float min,float max,int count);
			 void addValue(float value);
			 float* getAllSection(){return section;};
			 int  getCountSection(){return countSection;};
			 float getMin(){return min;}
			 float getMax(){return max;}
			 ~Histogram(){ delete section;}
	};


};
