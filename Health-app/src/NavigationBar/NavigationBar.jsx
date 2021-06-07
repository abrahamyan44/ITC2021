import React from 'react';
import './NavigationBar.css'
import Program from '../Program/Program';
import PlanList from '../PlanList/PlanList';
import Food from '../Food/Food';
import Notifications from '../Notification/Notifications';
import Account from '../Account/Account';
import Icon from '@mdi/react';
import {
    mdiHome,
    mdiBell,
    mdiFood,
    mdiAccount,
    mdiChartLine,
  } from '@mdi/js';
import { ToggleButton } from 'ui-neumorphism'
import { withRouter } from 'react-router';

class NavigationBar extends React.Component {
    render() {
        const {dark, page, setPage, setMode} = this.props;
        switch (page) {
            case 'Program':
                return (
                    <div>
                        <div className='fitness-app-nav-bar'>
                            <ToggleButton selected dark={dark} color='var(--primary)'>
                                <Icon path={mdiHome} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} onClick = {(event) => {setPage('ChartLine')}}>
                                <Icon path={mdiChartLine} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} onClick = {(event) => {setPage('Food')}}>
                                <Icon path={mdiFood} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Notifications')}}>
                                <Icon path={mdiBell} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Account')}}>
                                <Icon path={mdiAccount} size={1}></Icon>
                            </ToggleButton>
                        </div>
                    </div>
                )
                break;
            case 'ChartLine':
                return (
                    <div>
                        <div className='fitness-app-nav-bar'>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Program')}}>
                                <Icon path={mdiHome} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} selected color='var(--primary)'>
                                <Icon path={mdiChartLine} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} onClick = {(event) => {setPage('Food')}}>
                                <Icon path={mdiFood} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Notifications')}}>
                                <Icon path={mdiBell} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Account')}}>
                                <Icon path={mdiAccount} size={1}></Icon>
                            </ToggleButton>
                        </div>
                    </div>
                )
                break;
            case 'Food':
                return (
                    <div>
                        <div className='fitness-app-nav-bar'>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Program')}}>
                                <Icon path={mdiHome} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} onClick = {(event) => {setPage('ChartLine')}}>
                                <Icon path={mdiChartLine} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} selected color='var(--primary)'>
                                <Icon path={mdiFood} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Notifications')}}>
                                <Icon path={mdiBell} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Account')}}>
                                <Icon path={mdiAccount} size={1}></Icon>
                            </ToggleButton>
                        </div>
                    </div>
                )
                break;
            case 'Notifications':
                return (
                    <div>
                        <div className='fitness-app-nav-bar'>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Program')}}>
                                <Icon path={mdiHome} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} onClick = {(event) => {setPage('ChartLine')}}>
                                <Icon path={mdiChartLine} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} onClick = {(event) => {setPage('Food')}}>
                                <Icon path={mdiFood} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} selected color='var(--primary)'>
                                <Icon path={mdiBell} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Account')}}>
                                <Icon path={mdiAccount} size={1}></Icon>
                            </ToggleButton>
                        </div>
                    </div>
                )
                break;
            case 'Account':
                return (
                    <div>
                        <div className='fitness-app-nav-bar'>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Program')}}>
                                <Icon path={mdiHome} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} onClick = {(event) => {setPage('ChartLine')}}>
                                <Icon path={mdiChartLine} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton  dark={dark} onClick = {(event) => {setPage('Food')}}>
                                <Icon path={mdiFood} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} onClick = {(event) => {setPage('Notifications')}}>
                                <Icon path={mdiBell} size={1}></Icon>
                            </ToggleButton>
                            <ToggleButton dark={dark} selected color='var(--primary)'>
                                <Icon path={mdiAccount} size={1}></Icon>
                            </ToggleButton>
                        </div>
                    </div>
                )    
            break;
        } 
    }
}

export default withRouter(NavigationBar);