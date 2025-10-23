#include <gtest/gtest.h>
#include "CargoPaper.hpp"

TEST(CARGO_TEST, test_check_make_ticket_should_give_correct_information){
    CargoPaper ticket = CargoPaper("Taipei","Xizhi",20,20,CargoType::Food);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetTrainNumber(),0);
    ASSERT_EQ(ticket.GetVolume(),20);
    ASSERT_EQ(ticket.GetSrc(),"Xizhi");
    ASSERT_EQ(ticket.GetDest(),"Taipei");
    ASSERT_EQ(ticket.GetCargoType(),CargoType::Food);
    ASSERT_EQ(ticket.GetTrainType(),TrainType::Cargo);
    ASSERT_EQ(ticket.GetPrice(),88);
}
TEST(CARGO_TEST, test_check_cargopaper_should_give_calculate_diff_price_food){
    CargoPaper ticket = CargoPaper("Taipei","Song-Shan",10,100,CargoType::Food);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetPrice(),126);
}
TEST(CARGO_TEST, test_check_cargopaper_should_give_calculate_diff_price_drink){
    CargoPaper ticket = CargoPaper("Taipei","Song-Shan",10,80,CargoType::Drink);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetPrice(),44);
}
TEST(CARGO_TEST, test_check_cargopaper_should_give_calculate_diff_price_elec){
    CargoPaper ticket = CargoPaper("Taipei","Taoyuan",50,170,CargoType::Electronics);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetPrice(),316);
}
TEST(CARGO_TEST, test_check_cargopaper_should_give_calculate_diff_price_furniture){
    CargoPaper ticket = CargoPaper("Taipei","Taichung",200,340,CargoType::Furniture);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetPrice(),1178);
}
TEST(CARGO_TEST, test_check_cargopaper_should_give_calculate_diff_price_vehicle){
    CargoPaper ticket = CargoPaper("Taipei","Beking",2100,75,CargoType::Vehicle);
    ticket.CalculateTicketPrice();

    ASSERT_EQ(ticket.GetPrice(),16830);
}