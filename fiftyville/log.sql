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


--transcript: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |





-- to see the activity and licence from the security logs
SELECT activity,minute,license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;

--data found:
--activity | minute | license_plate |
--+----------+--------+---------------+
--| entrance | 8      | R3G7486       |
--| entrance | 14     | 13FNH73       |
--| exit     | 16     | 5P2BI95       |
--| exit     | 18     | 94KL13X       |
--| exit     | 18     | 6P58WS2       |
--| exit     | 19     | 4328GD8       |
--| exit     | 20     | G412CB7       |
--| exit     | 21     | L93JTIZ       |
--| exit     | 23     | 322W7JE       |
--| exit     | 23     | 0NTHK55       |
--| exit     | 35     | 1106N58       |