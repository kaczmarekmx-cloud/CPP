# Car Rental System — C++

Academic project — a console-based car rental management system written in C++.

> ⚠️ University project — code written for educational purposes.

---

## Features

- Load and save car database from/to CSV file
- View list of all cars and detailed info
- Filter cars by gearbox type (manual/auto)
- Check available cars in a given date range
- Rent and return cars with date tracking
- Add new cars to the database

---

## Menu

```
1. Exit
2. Load cars from CSV
3. View all cars
4. View car details
5. Show available cars in date range
6. Filter by gearbox type
7. Add new car
8. Rent a car
9. Return a car
10. Save to CSV
```
---

## Data Structure

Each car stores:

| Field | Description |
|---|---|
| `model` | Car model |
| `marka` | Car brand |
| `liczbaMiejsc` | Number of seats |
| `typNadwozia` | Body type |
| `nrRej` | License plate |
| `skrzynia` | Gearbox type (manual/auto) |
| `kolor` | Color |
| `pojCm3` | Engine displacement (cm³) |
| `dataWyp` | Last rental date |
| `dataZwrot` | Last return date |

---

## CSV Format

model,marka,liczba_miejsc,typ_nadwozia,nr_rejestracyjny,rodzaj_skrzyni,kolor,pojemnosc_cm3,data_ostatniego_wypozyczenia,data_ostatniego_zwrotu
Golf,Volkswagen,5,hatchback,WA12345,manual,czarny,1600,2024-01-10,2024-01-15

---

## Technologies
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
