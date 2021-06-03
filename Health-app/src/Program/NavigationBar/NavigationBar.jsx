import React from 'react';
import Icon from '@mdi/react';
import {
    mdiHome,
    mdiBell,
    mdiFood,
    mdiAccount,
    mdiChartLine,
  } from '@mdi/js';
import { ToggleButton } from 'ui-neumorphism'

class NavigationBar extends React.Component {
    render() {
        return (
            <div className='fitness-app-nav-bar'>
                <ToggleButton selected dark={false} color='var(--primary)'>
                    <Icon path={mdiHome} size={1}></Icon>
                </ToggleButton>
                <ToggleButton  dark={false}>
                    <Icon path={mdiChartLine} size={1}></Icon>
                </ToggleButton>
                <ToggleButton  dark={false}>
                    <Icon path={mdiFood} size={1}></Icon>
                </ToggleButton>
                <ToggleButton dark={false}>
                    <Icon path={mdiBell} size={1}></Icon>
                </ToggleButton>
                <ToggleButton dark={false}>
                    <Icon path={mdiAccount} size={1}></Icon>
                </ToggleButton>
                </div>
        )
    }
}

export default NavigationBar;