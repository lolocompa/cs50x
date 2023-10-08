-- find the description of the crime scene
 SELECT description
   ...> FROM crime_scene_reports
   ...> WHERE day = 28
   ...> AND month = '7'
   ...> AND year = 2021
   ...> AND street = 'Humphrey Street'
   ...> ;

-- description: Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
-- Littering took place at 16:36. No known witnesses.



-- to find the transcript of the witness
 SELECT transcript
   ...> FROM interviews
   ...> WHERE month = '7'
   ...> AND day = 28
   ...> AND year = 2021
   ...> ;


--transcript: