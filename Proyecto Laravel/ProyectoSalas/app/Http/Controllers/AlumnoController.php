<?php namespace App\Http\Controllers;




class AlumnoController extends Controller {


	protected $layout='layouts.master';

	public function getIndex()
	{

		return view('Alumno/indexAlumno');

	}

	public function getHorario()
	{
		return view('Alumno/Horario');
	}

}