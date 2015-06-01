<?php namespace App\Http\Controllers;




class DocenteController extends Controller {


	protected $layout='layouts.master';

	public function getIndex()
	{

		return view('Docente/indexDocente');

	}



}
