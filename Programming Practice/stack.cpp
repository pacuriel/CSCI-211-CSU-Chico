bool Stack::pop(int &value_out) {
    bool result = false;
    if (!isEmpty()) {
        value_out = m_values[m_count - 1];
        m_count--;
        result = true;
    }
    return result;
}
