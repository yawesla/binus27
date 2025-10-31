<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;

class ArticleSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        //
        \DB::table('articles')->insert([
            'title' => 'Sample Article Cross Country',
            'articleContent' => 'Laravel is a web application framework with expressive, elegant syntax. A web framework provides a structure and starting point for creating your application, allowing you to focus on creating something amazing while we sweat the details.',
            'author_id' => 1
        ]);
        \DB::table('articles')->insert([
            'title' => 'Sample Article Dieng',
            'articleContent' => 'Laravel is a web application framework with expressive, elegant syntax. A web framework provides a structure and starting point for creating your application, allowing you to focus on creating something amazing while we sweat the details.',
            'author_id' => 1
        ]);
        \DB::table('articles')->insert([
            'title' => 'Sample Article Fatahillah Museum',
            'articleContent' => 'Laravel is a web application framework with expressive, elegant syntax. A web framework provides a structure and starting point for creating your application, allowing you to focus on creating something amazing while we sweat the details.',
            'author_id' => 3
        ]);
    }
}
