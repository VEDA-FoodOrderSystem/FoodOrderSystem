#include "Review.h"

Review::Review(int review_id, int star, string content, int order_id) {
    this->review_id = review_id;
    this->star = star;
    this->content = content;
    this->order_id = order_id;
}

int Review::getId() {
    return review_id;
}

void Review::setStar(int star) {
    this->star = star;
}

double Review::getStar() {
    return star;
}

void Review::setContent(string& content) {
    this->content = content;
}

string Review::getContent() {
    return content;
}

void Review::setOrderId(int id) {
    order_id = id;
}

int Review::getOrderId() {
    return order_id;
}