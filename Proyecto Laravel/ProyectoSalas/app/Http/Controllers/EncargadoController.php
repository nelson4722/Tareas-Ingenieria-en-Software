<?php namespace App\Http\Controllers;




class EncargadoController extends Controller {


	protected $layout='layouts.master';

	public function getIndex()
	{

		return view('Encargado/indexEncargado');

	}

}
