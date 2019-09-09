#pragma once
#include <iostream>
#include <vector>
namespace Project20 {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
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
			 //private: System::Windows::Forms::Button^  Filtrar;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Mostrar_imagen = (gcnew System::Windows::Forms::Button());
			this->Filtrar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Mostrar_imagen
			// 
			this->Mostrar_imagen->Location = System::Drawing::Point(135, 402);
			this->Mostrar_imagen->Name = L"Mostrar_imagen";
			this->Mostrar_imagen->Size = System::Drawing::Size(75, 23);
			this->Mostrar_imagen->TabIndex = 0;
			this->Mostrar_imagen->Text = L"Mostrar";
			this->Mostrar_imagen->UseVisualStyleBackColor = true;
			this->Mostrar_imagen->Click += gcnew System::EventHandler(this, &MyForm::Mostrar_imagen_Click);
			// 
			// Filtrar
			// 
			this->Filtrar->Location = System::Drawing::Point(811, 402);
			this->Filtrar->Name = L"Filtrar";
			this->Filtrar->Size = System::Drawing::Size(64, 23);
			this->Filtrar->TabIndex = 1;
			this->Filtrar->Text = L"Filtrar";
			this->Filtrar->UseVisualStyleBackColor = true;
			this->Filtrar->Click += gcnew System::EventHandler(this, &MyForm::Filtrar_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1096, 477);
			this->Controls->Add(this->Filtrar);
			this->Controls->Add(this->Mostrar_imagen);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			//ahdolor

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
				a[der] = a[i];
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
		void quicksort(vector<int>* a, int n) {
			quick(a, 0, n - 1);
		}
		Color mediana(int x, int y, Bitmap^ ruido) {
			vector<int>* val = new vector<int>;
			int cont = 0, quiero = 0;
			for (int i = x - 1; i <= x + 1; i++) {
				for (int e = y - 1; e <= y + 1; e++) {
					val->push_back(ruido->GetPixel(i, e).ToArgb());//explotaba aqui antes|
					cont++;
				}
			}
			quicksort(val, 9);
			Color mediana = Color::FromArgb(val->at(4));
			return mediana;
		}
#pragma endregion
	private: System::Void Mostrar_imagen_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ graficador = this->CreateGraphics();
		Bitmap^ ruido = gcnew Bitmap("reduccion.jpg");
		Rectangle Aimg = Rectangle(30, 30, (ruido->Width*0.6), (ruido->Height*0.6));
		graficador->DrawImage(ruido, Aimg);
	}
	private: System::Void Filtrar_Click(System::Object^  sender, System::EventArgs^  e) {

		Graphics^ graficador = this->CreateGraphics();
		Bitmap^ ruido = gcnew Bitmap("reduccion.jpg");
		for (int i = 1; i < ruido->Height; i++) {//tal vez error con los pixeles que coge de la imagem(deberia ser hasta x-1 e y-1)
			for (int e = 1; e < ruido->Width; e++) {
				ruido->SetPixel(e, i, mediana(e, i, ruido));
			}
		}
		Rectangle Aimg = Rectangle(60 + ruido->Width, 60 + ruido->Height, (ruido->Width*0.6), (ruido->Height*0.6));
		graficador->DrawImage(ruido, Aimg);
	}
	};
}
