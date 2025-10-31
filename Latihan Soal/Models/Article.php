<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Article extends Model
{
    use HasFactory;

    function author(){
        //
        return $this->belongsTo(Author::class);
    }

    function categories(){
        //
        return $this->belongsToMany(Category::class);
    }
}
