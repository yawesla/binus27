<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Article;

class InformasiPariwisataController extends Controller
{
    //
    function home(){
        //
        $articles = Article::simplePaginate(2);

        return view('home', compact('articles'));
    }

    function readFull(Request $request){
        //
        $article = Article::find($request->id);
        $title = $article->title;
        $articleContent = $article->articleContent;
        $author = $article->author->name;

        return view('readFull', compact('title', 'articleContent', 'author'));
    }

    function category(){
        //
        $articles = Article::simplePaginate(2);

        return view('category', compact('articles'));
    }
    
}
