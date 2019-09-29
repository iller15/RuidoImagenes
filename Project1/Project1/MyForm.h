#pragma once
#include <comdef.h> 
#include <iostream>
#include <vector>
#include <ctime>
#include <gdiplus.h>  
#include <Gdipluscolor.h> 
#pragma comment(lib, "gdiplus.lib") 

namespace Project20 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Gdiplus;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private:
		int cont = 0;
		void Mostrar() {
			System::Drawing::Graphics ^ graficador = this->CreateGraphics();
			System::Drawing::Bitmap ^ruido = gcnew System::Drawing::Bitmap("300.jpg");
			System::Drawing::Rectangle Aimg = System::Drawing::Rectangle(30, 30, (ruido->Width), (ruido->Height));
			graficador->DrawImage(ruido, Aimg);
		}
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí

			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Mostrar_imagen;
	protected:
	private: System::Windows::Forms::Button^  Filtrar;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^ Canny;







	private: System::ComponentModel::IContainer^  components;
			 //private: System::Windows::Forms::Button^  Filtrar;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->Mostrar_imagen = (gcnew System::Windows::Forms::Button());
			this->Filtrar = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Canny = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Mostrar_imagen
			// 
			this->Mostrar_imagen->Location = System::Drawing::Point(55, 430);
			this->Mostrar_imagen->Name = L"Mostrar_imagen";
			this->Mostrar_imagen->Size = System::Drawing::Size(75, 23);
			this->Mostrar_imagen->TabIndex = 0;
			this->Mostrar_imagen->Text = L"Mostrar";
			this->Mostrar_imagen->UseVisualStyleBackColor = true;
			this->Mostrar_imagen->Click += gcnew System::EventHandler(this, &MyForm::Mostrar_imagen_Click);
			// 
			// Filtrar
			// 
			this->Filtrar->Location = System::Drawing::Point(730, 430);
			this->Filtrar->Name = L"Filtrar";
			this->Filtrar->Size = System::Drawing::Size(64, 23);
			this->Filtrar->TabIndex = 1;
			this->Filtrar->Text = L"Filtrar";
			this->Filtrar->UseVisualStyleBackColor = true;
			this->Filtrar->Click += gcnew System::EventHandler(this, &MyForm::Filtrar_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::Imprime);
			// 
			// Canny
			// 
			this->Canny->Location = System::Drawing::Point(900, 430);
			this->Canny->Name = L"Canny";
			this->Canny->Size = System::Drawing::Size(64, 23);
			this->Canny->TabIndex = 2;
			this->Canny->Text = L"Canny";
			this->Canny->UseVisualStyleBackColor = true;
			this->Canny->Click += gcnew System::EventHandler(this, &MyForm::Canny_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1191, 514);
			this->Controls->Add(this->Canny);
			this->Controls->Add(this->Filtrar);
			this->Controls->Add(this->Mostrar_imagen);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
		int pivot(vector<int>* a, int i, int f) {
			int piv = a->at(i); int izq = i + 1; int der = f;
			while (der >= izq) {
				if (a->at(izq) <= piv) ++izq;
				else if (a->at(der) >= piv) --der;
				else {
					int t = a->at(der);
					a->at(der--) = a->at(izq);
					a->at(izq++) = t;

				}
			}
			if (der != i) {
				int t = a->at(der);
				a->at(der) = a->at(i);
				a->at(i) = t;
			}
return der;
		}
		void quick(vector<int>* a, int i, int f) {
			if (f > i) {
				int p = pivot(a, i, f);
				quick(a, i, p - 1);
				quick(a, p + 1, f);
			}
		}
		void quicksort(vector<int> * a, int n) {
			quick(a, 0, n - 1);
		}
		System::Drawing::Color mediana(int x, int y, System::Drawing::Bitmap ^ ruido) {
			x--; y--;
			vector<int>* val = new vector<int>;
			//for (int i = x; i <= x + 2; i++) {	  //	for (int i = x - 1; i <= x + 1; i++) {	
			//	for (int e = y; e <= y + 2; e++) {// for (int e = y - 1; e <= y + 1; e++)
			//		val->push_back(ruido->GetPixel(i, e).ToArgb());//explotaba aqui antes|
			//	}
			//}

			//for (int i = x; i <= x + 2; i++) {	  //	for (int i = x - 1; i <= x + 1; i++) {	
			//for (int e = y; e <= y + 2; e++) {// for (int e = y - 1; e <= y + 1; e++)
			val->push_back(ruido->GetPixel(x, y).ToArgb());//explotaba aqui antes|
			val->push_back(ruido->GetPixel((x + 1), y).ToArgb());
			val->push_back(ruido->GetPixel((x + 2), y).ToArgb());
			val->push_back(ruido->GetPixel(x, (y + 1)).ToArgb());
			val->push_back(ruido->GetPixel((x + 2), (y + 1)).ToArgb());
			val->push_back(ruido->GetPixel((x + 1), (y + 1)).ToArgb());
			val->push_back(ruido->GetPixel(x, y + 2).ToArgb());
			val->push_back(ruido->GetPixel((x + 1), (y + 2)).ToArgb());
			val->push_back(ruido->GetPixel((x + 2), (y + 2)).ToArgb());

			//}
			//}
			quicksort(val, val->size());
			System::Drawing::Color mediana = System::Drawing::Color::FromArgb(val->at(4));
			val->clear();
			return mediana;
		}

		System::Drawing::Color canny(int x, int y, System::Drawing::Bitmap ^ ruido) {
			vector<int>* val = new vector<int>;
			//for (int i = x; i <= x + 2; i++) {	  //	for (int i = x - 1; i <= x + 1; i++) {	
			//	for (int e = y; e <= y + 2; e++) {// for (int e = y - 1; e <= y + 1; e++)
			//		val->push_back(ruido->GetPixel(i, e).ToArgb());//explotaba aqui antes|
			//	}
			//}

			//for (int i = x; i <= x + 2; i++) {	  //	for (int i = x - 1; i <= x + 1; i++) {	
			//for (int e = y; e <= y + 2; e++) {// for (int e = y - 1; e <= y + 1; e++)
			val->push_back(ruido->GetPixel((x - 1), (y - 1)).ToArgb());//explotaba aqui antes|
			val->push_back(ruido->GetPixel(x, (y - 1)).ToArgb());
			val->push_back(ruido->GetPixel((x + 1), (y - 1)).ToArgb());
			val->push_back(ruido->GetPixel((x - 1), y).ToArgb());
			val->push_back(ruido->GetPixel(x, y).ToArgb());
			val->push_back(ruido->GetPixel((x + 1), y).ToArgb());
			val->push_back(ruido->GetPixel(x - 1, y + 1).ToArgb());
			val->push_back(ruido->GetPixel(x, (y + 1)).ToArgb());
			val->push_back(ruido->GetPixel((x + 1), (y + 1)).ToArgb());

			//}
			//}
			// Gx
			// -1  0  1
			// -2  0  2
			// -1  0  1
			int Gx = (val->at(0) * -1) + (val->at(1) * 0) + (val->at(2) * 1)
				+ (val->at(3) * -2) + (val->at(4) * 0) + (val->at(5) * 2)
				+ (val->at(6) * -1) + (val->at(7) * 0) + (val->at(8) * 1);
			//Gy
			// -1 -2 -1
			//  0  0  0
			//  1  2  1
			int Gy = (val->at(0) * -1) + (val->at(1) * -2) + (val->at(2) * -1)
				+ (val->at(3) * 0) + (val->at(4) * 0) + (val->at(5) * 0)
				+ (val->at(6) * 1) + (val->at(7) * 2) + (val->at(8) * 1);
			//G
			int G = sqrt(pow(Gx, 2) + pow(Gy, 2));
			//orientación
			if (Gx != 0) {
				double orient = atan(Gy / Gx);
			}
			else double orient = atan(tan(90));

			System::Drawing::Color rcanny;
			//limites
			if (G > 8000000) {
				rcanny = System::Drawing::Color::Black;
			}
			else if (G > 4200000) {
				rcanny = System::Drawing::Color::Blue;
			}
			else rcanny = System::Drawing::Color::White;

			val->clear();
			return rcanny;
		}

		bool PerteneceLinea(int x, int y, System::Drawing::Bitmap ^ ruido) {
			if (EsAzul(x,y,ruido)) {
				if (ruido->GetPixel(x - 1, y - 1).ToArgb() == System::Drawing::Color::Black.ToArgb()
					|| ruido->GetPixel(x - 1, y).ToArgb() == System::Drawing::Color::Black.ToArgb()
					|| ruido->GetPixel(x - 1, y + 1).ToArgb() == System::Drawing::Color::Black.ToArgb()
					|| ruido->GetPixel(x, y - 1).ToArgb() == System::Drawing::Color::Black.ToArgb()
					|| ruido->GetPixel(x, y + 1).ToArgb() == System::Drawing::Color::Black.ToArgb()
					|| ruido->GetPixel(x + 1, y - 1).ToArgb() == System::Drawing::Color::Black.ToArgb()
					|| ruido->GetPixel(x + 1, y).ToArgb() == System::Drawing::Color::Black.ToArgb()
					|| ruido->GetPixel(x + 1, y + 1).ToArgb() == System::Drawing::Color::Black.ToArgb()) {
					return true;
				}
				else return false;
			}
			return false;
		}
		bool EsAzul(int x, int y, System::Drawing::Bitmap^ ruido) {
			if (ruido->GetPixel(x, y).ToArgb() == System::Drawing::Color::Blue.ToArgb()) {
				return true;
			}
			else return false;
		}

		int GetEncoderClsid(const WCHAR* format, CLSID* pClsid) {
			UINT  num = 0;          // number of image encoders 
			UINT  size = 0;         // size of the image encoder array in bytes 
			ImageCodecInfo* pImageCodecInfo = NULL;
			GetImageEncodersSize(&num, &size);
			if (size == 0)
				return -1;  // Failure 
			pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
			if (pImageCodecInfo == NULL)
				return -1;  // Failure 
			GetImageEncoders(num, size, pImageCodecInfo);
			for (UINT j = 0; j < num; ++j)
			{
				if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
				{
					*pClsid = pImageCodecInfo[j].Clsid;
					free(pImageCodecInfo);
					return j;  // Success 
				}
			}
			free(pImageCodecInfo);
			return -1;  // Failure 
		}
		void ToGrey(Gdiplus::Bitmap *ruido2, Gdiplus::Bitmap *original) {
			for (int i = 0; i < (original->GetHeight() - 1); i++) {//tal vez error con los pixeles que coge de la imagem(deberia ser hasta x-1 e y-1)
				for (int e = 0; e < (original->GetWidth() - 1); e++) {
					Gdiplus::Color c;
					original->GetPixel(e, i, &c);
					BYTE average = (BYTE)((c.GetRed() + c.GetGreen() + c.GetBlue()) / 3);
					ruido2->SetPixel(e, i, Gdiplus::Color(average, average, average));
				}
			}

		}

#pragma endregion
	private: System::Void Mostrar_imagen_Click(System::Object^  sender, System::EventArgs^  e) {
		GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		Gdiplus::Bitmap *og = Gdiplus::Bitmap::FromFile(L"reduccion.jpg");
		Gdiplus::Bitmap *cambiado = new Gdiplus::Bitmap(og->GetWidth(), og->GetHeight());
		this->ToGrey(cambiado, og);																	//Vuelves la imagen blacno y negro para luego editarla
		CLSID pngClsid;

		if (GetEncoderClsid(L"ruido.jpg", &pngClsid))
			cambiado->Save(L"cambio1.jpg", &pngClsid, NULL);
		else
			cout << "nope" << endl;
		delete og;
		delete cambiado;
		og = NULL;
		cambiado = NULL;
		GdiplusShutdown(gdiplusToken);
		//ahora con laimagen a blanco y negro con los metods de forms?
		System::Drawing::Graphics ^ graficador = this->CreateGraphics();
		System::Drawing::Bitmap ^ruido = gcnew System::Drawing::Bitmap("cambio1.jpg");
		System::Drawing::Rectangle Aimg = System::Drawing::Rectangle(30, 30, (ruido->Width*0.6), (ruido->Height*0.6));
		graficador->DrawImage(ruido, Aimg);
		cout << "Salio" << endl;

	}
	private: System::Void Filtrar_Click(System::Object^  sender, System::EventArgs^  e) {
		System::Drawing::Graphics^ graficador = this->CreateGraphics();
		System::Drawing::Bitmap^ ruido = gcnew System::Drawing::Bitmap("300.jpg");
		for (char i = 0; i <= 1; i++) {
			for (int i = 1; i < (ruido->Height - 1); i++) {//tal vez error con los pixeles que coge de la imagem(deberia ser hasta x-1 e y-1)
				for (int e = 1; e < (ruido->Width - 1); e++) {
					ruido->SetPixel(e, i, mediana(e, i, ruido));
				}
			}
		}
		System::Drawing::Rectangle Aimg = System::Drawing::Rectangle(60 + ruido->Width, 30, (ruido->Width), (ruido->Height));
		graficador->DrawImage(ruido, Aimg);
	}
	private: System::Void Start_imprime(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void Imprime(System::Object^  sender, System::EventArgs^  e) {
		this->Mostrar();
		this->timer1->Enabled = false;
	}
private: System::Void Canny_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Drawing::Graphics^ graficador = this->CreateGraphics();
	System::Drawing::Bitmap^ ruido = gcnew System::Drawing::Bitmap("300.jpg");
	System::Drawing::Bitmap^ ruido2 = gcnew System::Drawing::Bitmap("300.jpg");
	for (char a = 0; a <= 1; a++) {
		for (int i = 1; i < (ruido->Height - 1); i++) {//tal vez error con los pixeles que coge de la imagem(deberia ser hasta x-1 e y-1)
			for (int e = 1; e < (ruido->Width - 1); e++) {
				ruido->SetPixel(e, i, mediana(e, i, ruido));
			}
		}
	}

	//colocar lineas blancas a los bordes notorios, azules a los medios y quitar los bordes débiles;
	for (char a = 0; a <= 1; a++) {
		for (int i = 1; i < (ruido->Height - 1); i++) {//tal vez error con los pixeles que coge de la imagem(deberia ser hasta x-1 e y-1)
			for (int e = 1; e < (ruido->Width - 1); e++) {
				ruido2->SetPixel(e, i, canny(e, i, ruido));
			}
		}
	}

	//cambiar las lineas azules a blancas si son adyacentes a una linea blanca
	bool HayCambio = false;
	do{
		HayCambio = false;
		for (char a = 0; a <= 1; a++) {
			for (int i = 1; i < (ruido2->Height - 1); i++) {//tal vez error con los pixeles que coge de la imagem(deberia ser hasta x-1 e y-1)
				for (int e = 1; e < (ruido2->Width - 1); e++) {
					if (PerteneceLinea(e, i, ruido2)) {
						ruido2->SetPixel(e, i, System::Drawing::Color::Black);
						HayCambio = true;
					}
				}
			}
		}
	} while (HayCambio);

	//borrar las lineas azules que no estan unidas a lineas blancas
	for (char a = 0; a <= 1; a++) {
		for (int i = 1; i < (ruido2->Height - 1); i++) {//tal vez error con los pixeles que coge de la imagem(deberia ser hasta x-1 e y-1)
			for (int e = 1; e < (ruido2->Width - 1); e++) {
				if (EsAzul(e, i, ruido2)) {
					ruido2->SetPixel(e, i, System::Drawing::Color::White);
				}
			}
		}
	}

	System::Drawing::Rectangle Aimg = System::Drawing::Rectangle(90 + 2*ruido->Width, 30, (ruido->Width), (ruido->Height));
	graficador->DrawImage(ruido2, Aimg);
}
};
}
