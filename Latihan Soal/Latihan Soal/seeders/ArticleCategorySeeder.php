<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;

class ArticleCategorySeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        //
        \DB::table('article_category')->insert([
            'article_id' => 1,
            'category_id' => 2
        ]);
        \DB::table('article_category')->insert([
            'article_id' => 1,
            'category_id' => 3
        ]);
        \DB::table('article_category')->insert([
            'article_id' => 2,
            'category_id' => 2
        ]);
        \DB::table('article_category')->insert([
            'article_id' => 3,
            'category_id' => 4
        ]);
    }
}
