import React from 'react';
import './NavigationBar.css'
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
        const {dark, selected} = this.props;
        switch (selected) {
            case 'Home':
                return (
                    <div className='fitness-app-nav-bar'>
                        <ToggleButton selected dark={dark} color='var(--primary)'>
                            <Icon path={mdiHome} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark}>
                            <Icon path={mdiChartLine} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark}>
                            <Icon path={mdiFood} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiBell} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiAccount} size={1}></Icon>
                        </ToggleButton>
                    </div>
                )
                break;
            case 'ChartLine':
                return (
                    <div className='fitness-app-nav-bar'>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiHome} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark} selected color='var(--primary)'>
                            <Icon path={mdiChartLine} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark}>
                            <Icon path={mdiFood} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiBell} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiAccount} size={1}></Icon>
                        </ToggleButton>
                    </div>
                )
                break;
            case 'Food':
                return (
                    <div className='fitness-app-nav-bar'>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiHome} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark}>
                            <Icon path={mdiChartLine} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark} selected color='var(--primary)'>
                            <Icon path={mdiFood} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiBell} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiAccount} size={1}></Icon>
                        </ToggleButton>
                    </div>
                )
                break;
            case 'Notifications':
                return (
                    <div className='fitness-app-nav-bar'>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiHome} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark}>
                            <Icon path={mdiChartLine} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark}>
                            <Icon path={mdiFood} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark} selected color='var(--primary)'>
                            <Icon path={mdiBell} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiAccount} size={1}></Icon>
                        </ToggleButton>
                    </div>
                )
                break;
            case 'Account':
                return (
                    <div className='fitness-app-nav-bar'>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiHome} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark}>
                            <Icon path={mdiChartLine} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton  dark={dark}>
                            <Icon path={mdiFood} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark}>
                            <Icon path={mdiBell} size={1}></Icon>
                        </ToggleButton>
                        <ToggleButton dark={dark} selected color='var(--primary)'>
                            <Icon path={mdiAccount} size={1}></Icon>
                        </ToggleButton>
                    </div>
                )    
            break;
        } 
    }
}

export default NavigationBar;