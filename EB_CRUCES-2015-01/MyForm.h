/**
*
* MyForm.h
*
* EXAMEN FINAL 2015-01 (Programación 2 - UPC)
*
* @author Brayan Cruces (brayancru.com)
* @since 1.0.0
* @version 1.0.0, 07/07/2015
*
*/

#pragma once
#include "ArrPokemon.h" //1- hacer include

namespace EB_CRUCES201501 {

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
	public:
		MyForm(void)
		{
			objArreglo = new ArrPokemon(); // 2- Crear instancia de objeto

			// Insertamos multipes piedras al iniciar 
			for (int i = 0; i < 25; i++){ objArreglo->Insertar(1); } //Piedra Agua
			for (int i = 0; i < 25; i++){ objArreglo->Insertar(2); } //Piedra Fuego

			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

			delete objArreglo; // 3- Eliminar objeto
		}
	private: ArrPokemon* objArreglo; // 4- Nombrar la instancia (proviene de..)
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 561);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		/* CONCATENAMIENTO (Titulo de la ventana) */
		this->Text = "Blastoise: " + objArreglo->GET_contBlastoise().ToString() +
			" | Charizard: " + objArreglo->GET_contCharizard().ToString();

		/* BUFFER */
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics ^buffer = espacioBuffer->Allocate(g, this->ClientRectangle);

		buffer->Graphics->Clear(Color::White);

		objArreglo->MoverTodo(buffer->Graphics);

		buffer->Render(g);

		delete buffer;
		delete espacioBuffer;
		delete g;

	}
	};
}
