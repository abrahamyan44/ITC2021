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
import { ToggleButton, ToggleButtonGroup } from 'ui-neumorphism'
import { NavLink } from 'react-router-dom';

class NavigationBar extends React.Component {
    constructor(props) {
        super(props)
        this.state = {
          mandatoryActive: '1',
        }
      }
    mandatoryGroupChange(e) {
      this.setState({ mandatoryActive: e.active })
    }
    render() {
        const {dark} = this.props;
        return (
            <ToggleButtonGroup 
                className='fitness-app-nav-bar' 
                mandatory 
                color='var(--primary)'
                onChange={this.mandatoryGroupChange.bind(this)}
            >
                <ToggleButton selected value='1' dark={dark}>
                    <NavLink className='link' to='/'>
                        <Icon path={mdiHome} size={1} dark={dark}></Icon>
                    </NavLink>
                </ToggleButton>
                <ToggleButton value='2' dark={dark}>
                    <NavLink className='link' to='/PlanList'>
                        <Icon path={mdiChartLine} size={1}></Icon>
                    </NavLink>
                </ToggleButton>
                <ToggleButton value='3' dark={dark}>
                    <NavLink className='link' to='/Food'>
                        <Icon path={mdiFood} size={1}></Icon>
                    </NavLink>
                </ToggleButton>
                <ToggleButton value='4' dark={dark}>
                    <NavLink className='link' to='/Notification'>
                        <Icon path={mdiBell} size={1}></Icon>
                    </NavLink>
                </ToggleButton>
                <ToggleButton value='5' dark={dark}>
                    <NavLink className='link' to='/Account'>
                        <Icon path={mdiAccount} size={1}></Icon>
                    </NavLink>
                </ToggleButton>
            </ToggleButtonGroup>
        )
    }
}

export default NavigationBar;