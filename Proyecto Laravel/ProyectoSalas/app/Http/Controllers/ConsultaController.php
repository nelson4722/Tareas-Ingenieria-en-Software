<?php namespace App\Http\Controllers;




class ConsultaController extends Controller {


	protected $layout='layouts.master';


	public function getconsultaAlumno()
	{
		return view('/Alumno/consultaAlumno');
	}

	public function getconsultaDocente()
	{
		return view('/Docente/consultaDocente');
	}


}
