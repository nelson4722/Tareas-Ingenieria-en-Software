<?php namespace App\Http\Controllers;

use App\models\Alumno;


class AlumnoController extends Controller {


	protected $layout='layouts.master';

	public function getIndex()
	{	
		
		return view('Alumno/indexAlumno');

	}

	

	

}
