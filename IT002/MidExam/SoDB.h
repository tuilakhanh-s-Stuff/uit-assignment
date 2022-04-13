typedef class SoDacBiet
{
	private:
		int n;
	public:
		SoDacBiet(int n = 1)
		{
			this->n = n;
		}
		int getN();
		void setN(int);
		void Nhap();
		bool KiemTraSNT();
		bool KiemTraSCP();
		bool KiemTraSHT();
		bool KiemTraSDX();
		void Xuat();
} SoDB;
