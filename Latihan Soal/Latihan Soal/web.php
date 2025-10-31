<?php

use Illuminate\Support\Facades\Route;

use App\Http\Controllers\InformasiPariwisataController;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/home', [InformasiPariwisataController::class, 'home']);
Route::get('/readFull/{id}', [InformasiPariwisataController::class, 'readFull']);
Route::get('/category', [InformasiPariwisataController::class, 'category']);
