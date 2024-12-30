#pragma once
#include <functional>
#include "base-component.hpp"

namespace eclipse::gui {
    /// @brief Radio button component for selecting one of the options.
    class RadioButtonComponent : public Component {
    public:
        explicit RadioButtonComponent(std::string id, std::string title, int value);

        void onInit() override {}
        void onUpdate() override {}

        /// @brief Set a callback function to be called when the component value changes.
        RadioButtonComponent* callback(const std::function<void(int)>& func);

        /// @brief Get the radio button value.
        [[nodiscard]] int getValue() const;

        /// @brief Set the radio button value.
        void setValue(int value) const;

        [[nodiscard]] int getChoice() const;

        /// @brief Allows to set keybinds for the radio button.
        RadioButtonComponent* handleKeybinds();

        [[nodiscard]] const std::string& getId() const override;
        [[nodiscard]] const std::string& getTitle() const override;
        [[nodiscard]] bool hasKeybind() const;

        void triggerCallback(int value) const;

        RadioButtonComponent* setDescription(std::string description) override;

    private:
        std::string m_id;
        std::string m_title;
        int m_value;
        std::function<void(int)> m_callback;
        bool m_hasKeybind = false;
    };
}
