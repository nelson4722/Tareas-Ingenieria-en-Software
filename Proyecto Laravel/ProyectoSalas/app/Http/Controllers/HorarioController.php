<?php namespace App\Http\Controllers;




class HorarioController extends Controller {


	protected $layout='layouts.master';


	public function getHorario()
	{
		return view('Alumno/Horario');
	}

	public function getHorarioDocente()
	{
		return view('Docente/HorarioDocente');
	}

}
