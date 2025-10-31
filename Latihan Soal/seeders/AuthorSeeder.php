<?php

namespace Database\Seeders;

use Illuminate\Database\Console\Seeds\WithoutModelEvents;
use Illuminate\Database\Seeder;

use Faker\Factory as Faker;

class AuthorSeeder extends Seeder
{
    /**
     * Run the database seeds.
     */
    public function run(): void
    {
        //
        $faker = Faker::create('id_ID');
        for($i = 1; $i <= 5; $i++){
            \DB::table('authors')->insert([
                'name' => $faker->name,
                'email' => $faker->email
            ]);
        }
    }
}
